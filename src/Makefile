include ../flags.mk

DIRS = rpn
OUTS = calc

all : ../bin ../bin/librpn.a ../bin/librpn.so $(foreach out,$(OUTS),../bin/$(out).out)
	
../bin:
	mkdir -p ../bin
../bin/librpn.a : $(foreach dir,$(DIRS),$(dir).dir.o)
	rm -f $@
	ar cq $@ $+
../bin/librpn.so : $(foreach dir,$(DIRS),$(dir).dir.o)
	rm -f $@
	ld -G -o $@ $+
../bin/%.out : %.cpp $(foreach dir,$(DIRS),$(dir).dir.o)
	${LINKER} -o $@ $+

include ../common.mk
