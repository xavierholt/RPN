SHELL := bash

OUTS = calc

default: libraries executables

libraries: build/libRPN.a build/libRPN.so build/RPN.h

executables: $(foreach out,$(OUTS),bin/$(out).out)

src/rpn.dir.o: force
	cd src; make -r
	
recompile: force
	make clean
	cd src; make -r

build:
	mkdir -p build
build/libRPN.a: build src/rpn.dir.o
	rm -f $@
	EXTRAS = -fdata-sections -ffunction-sections
	make recompile
	ar cq $@ $+
build/libRPN.so: build src/rpn.dir.o
	rm -f $@
	EXTRAS = -fPIC
	make recompile
	ar cq $@ $+
build/RPN.h: build src/rpn/rpn.h
	cpp -o $@ $<

bin:
	mkdir -p bin
bin/%.out: bin src/%.cpp build/libRPN.a
	${LINKER} -o $@ $+

install: build/RPN.h build/libRPN.a build/libRPN.so
	cp build/RPN.h     /usr/local/include
	cp build/libRPN.a  /usr/local/lib
	cp build/libRPN.so /usr/local/lib
	ldconfig -n /usr/local/lib

include common.mk
