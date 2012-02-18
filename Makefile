default:
	cd src; make -r
install: build/rpn.h build/librpn.a build/librpn.so
	cp build/rpn.h     /usr/local/include
	cp build/librpn.a  /usr/local/lib
	cp build/librpn.so /usr/local/lib
	ldconfig -n /usr/local/lib

build/rpn.h : src/rpn/rpn.h
	cpp -o $@ $<

include common.mk
