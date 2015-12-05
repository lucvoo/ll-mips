objs-y	:=
objs-y	+= lib/diag.o
objs-y	+= lib/diag-hexval.o
objs-y	+= lib/diag-hexdump.o

libs += lib/lib.a
lib/lib.a: $(objs-y)
lib/: lib/lib.a

objs += $(objs-y)
