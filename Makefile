####################################
# Avoid to:
# o  use make's built-in rules and variables
# o  print "Entering directory ...";
MAKEFLAGS += --no-builtin-rules
MAKEFLAGS += --no-builtin-variables
MAKEFLAGS += --no-print-directory
.SUFFIXES:

# all include directives are relative to the root dir
MAKEFLAGS += --include-dir=$(CURDIR)

####################################
# Be quiet by default.
# Use 'make V=1' to see the full commands

ifeq ("$(origin V)", "command line")
  Q 	:=
else
  Q	:= @
endif
export Q

####################################
.PHONY: all FORCE
all:
FORCE:

.PHONY: clean distclean
clean: FORCE
	@echo "CLEAN"
	$(Q)git clean -x -d -q -e .config

distclean: FORCE
	@echo "DISTCLEAN"
	@$(Q)git clean -x -d -q

####################################
# Read in config
include include/config


PFLAGS-y	:= -Iinclude -include include/config.h
CFLAGS-y	:= -include include/kernel.h
CFLAGS-y	+= -Wall -Wundef -Wno-trigraphs
CFLAGS-y	+= -Wstrict-prototypes
CFLAGS-y	+= -Wmissing-prototypes
CFLAGS-y	+= -Wmissing-declarations
CFLAGS-y	+= -Wimplicit
CFLAGS-y	+= -Wwrite-strings -Wunknown-pragmas -Wcast-qual -Wcast-align
CFLAGS-y	+= -Wsign-compare
CFLAGS-y	+= -Wno-unused-function
CFLAGS-y	+= -nostdinc -ffreestanding
CFLAGS-y	+= -fno-ident
CFLAGS-y	+= -Os 
CFLAGS-y	+= -ffunction-sections -fdata-sections
AFLAGS-y	:=-D__ASSEMBLY__ -fverbose-asm

arch/$(CONFIG_ARCH)/Makefile.arch: ;
include arch/$(CONFIG_ARCH)/Makefile.arch

CFLAGS-y	+= ${ARCHFLAGS-y}
AFLAGS-y	+= ${ARCHFLAGS-y}


ifdef	CONFIG_CROSS_COMPILE
CROSS_COMPILE := $(CONFIG_CROSS_COMPILE)
endif

CC	:= $(CROSS_COMPILE)gcc
AR	:= $(CROSS_COMPILE)ar
OBJCOPY	:= $(CROSS_COMPILE)objcopy
READELF	:= $(CROSS_COMPILE)readelf
CPP	:= $(CC) -E

SYS_INCDIR := $(shell $(CC) -print-file-name=include)
CFLAGS-y   += -isystem $(SYS_INCDIR)
#######################################################################
# avoid implicit rules
Makefile: ;
Makefile.rules: ;
include Makefile.rules

libs :=
objs :=
deps :=
apps :=

include arch/mips/Makefile
include drivers/Makefile
include irq/Makefile
include kernel/Makefile
include lib/Makefile

include apps/Makefile

-include $(foreach d,$(deps),$(dir $(d)).$(notdir $(d)).d)
-include $(foreach o,$(objs),$(dir $(d)).$(notdir $(d)).o.d)
-include $(libs:%/lib.a=%/.lib.a.d)
-include $(apps:apps/%=apps/.%.o.d)

#######################################################################

libtarget.a: $(libs)
	@echo 'AR	$@'
	$(Q)echo "GROUP($^)" > $@


all: libtarget.a FORCE


LDFLAGS+= -static -nostdlib
LDFLAGS+= -Wl,--gc-sections
LDFLAGS+=$(LDFLAGS-y)

apps-deps := libtarget.a arch/$(CONFIG_ARCH)/target.lds
apps/: $(apps:%=%.bin)
$(apps): %: %.o $(apps-deps) $(libs) kernel/version.o
	@echo "LINK	$@"
	$(Q)$(CC) -Wl,--gc-sections				\
		-Wl,-Map,$@.map,--cref				\
		-Tarch/$(CONFIG_ARCH)/target.lds $(LDFLAGS) 	\
		-Wl,--start-group				\
			-Wl,--whole-archive			\
				libtarget.a			\
			-Wl,--no-whole-archive			\
		-Wl,--end-group					\
		-lgcc						\
		$< $(libs) kernel/version.o -o $@
	@cp $@ kimage.elf

LOADADDR:=$(shell printf 0x%08x $$((${CONFIG_PHYS_ADDR} + ${CONFIG_TEXT_OFFSET})))
apps/%.uimg: apps/%.bin
	$(Q)mkimage -A $(CONFIG_ARCH) -T kernel -O linux -C none -e ${LOADADDR} -a ${LOADADDR} -d $< $@
apps/%.tftp: apps/%.uimg
	$(Q)cp $< /tftpboot/$(CONFIG_MACH).uimg

kernel/version.o: $(apps:%=%.o) $(apps-deps)
