deps	+= arch/mips/target.lds

objs-y	:=
objs-y	+= arch/mips/dump-stack.o
objs-y	+= arch/mips/dump-system-regs.o
objs-y	+= arch/mips/exceptions.o
objs-y	+= arch/mips/iomap.o
objs-y	+= arch/mips/startup.o
objs-y	+= arch/mips/vectors.o


libs += arch/mips/lib.a
arch/mips/lib.a: $(objs-y)
arch/mips/: arch/mips/lib.a

objs += $(objs-y)

include arch/mips/mach-ci20/Makefile
include arch/mips/soc-jz4780/Makefile
