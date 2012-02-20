ROOTDIR := $(dir $(CURDIR)/$(word $(words $(MAKEFILE_LIST)),$(MAKEFILE_LIST)))
BINDIR := $(ROOTDIR)/bin
LIBDIR := $(ROOTDIR)/src/rpn
SRCDIR := $(ROOTDIR)/src

COMPILER := g++ -Wall -Wextra -Werror -ansi -O3
BUNDLER := ld -Ur

ifdef DEBUG
	COMPILER := $(COMPILER) -g
endif

LINKER := $(COMPILER) -Wl,--gc-sections,-s

