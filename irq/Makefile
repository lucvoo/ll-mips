objs-y	:=
objs-y	+= irq/action.o
objs-y	+= irq/chip.o
objs-y	+= irq/handler.o

libs += irq/lib.a
irq/lib.a: $(objs-y)
irq/: irq/lib.a

objs += $(objs-y)
