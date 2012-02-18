include ../flags.mk

DIRS = rpn
OUTS = calc

all : ../bin ../bin/librpn.a $(foreach out,$(OUTS),../bin/$(out).out)

../bin:
	mkdir -p ../bin
../bin/librpn.a : $(foreach dir,$(DIRS),$(dir).dir.o)
	rm -f $@
	ar cq $@ $+
../bin/%.out : %.cpp ../bin/librpn.a
	${LINKER} -o $@ $+

include ../common.mk
