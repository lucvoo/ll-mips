objs-y	:=
objs-$(CONFIG_SOC_JZ4780)	+= drivers/irq/jz4780-intc.o
objs-$(CONFIG_ARCH_MIPS)	+= drivers/irq/mips-cpu.o

libs += drivers/irq/lib.a
drivers/irq/lib.a: $(objs-y)
drivers/irq/: drivers/irq/lib.a

objs += $(objs-y)
