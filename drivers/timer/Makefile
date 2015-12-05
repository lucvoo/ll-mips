objs-y	:=
objs-$(CONFIG_SOC_JZ4780)	+= drivers/timer/jz4780-timer.o

libs += drivers/timer/lib.a
drivers/timer/lib.a: $(objs-y)
drivers/timer/: drivers/timer/lib.a

objs += $(objs-y)
