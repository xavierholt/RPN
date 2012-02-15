include ../flags.mk

DIRS = rpn
OUTS = calc

all : $(foreach out,$(OUTS),../bin/$(out).out)
	
../bin/%.out : %.cpp $(foreach dir,$(DIRS),$(dir).dir.o)
	${LINKER} -o $@ $+

include ../common.mk
