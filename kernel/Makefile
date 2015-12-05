objs-y	:=
objs-y	+= kernel/idle.o
objs-y	+= kernel/main.o
objs-y	+= kernel/stacks.o
objs-y	+= kernel/timer.o

libs += kernel/lib.a
kernel/lib.a: $(objs-y)
kernel/: kernel/lib.a

objs += $(objs-y)
