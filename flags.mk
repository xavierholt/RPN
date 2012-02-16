ROOTDIR := $(dir $(CURDIR)/$(word $(words $(MAKEFILE_LIST)),$(MAKEFILE_LIST)))
BINDIR := $(ROOTDIR)/bin
LIBDIR := $(ROOTDIR)/src/rpn
SRCDIR := $(ROOTDIR)/src

MOC := moc-qt4
COMPILER := g++ -Wall -Wextra -std=c++0x -fdata-sections -ffunction-sections
BUNDLER := ld -Ur

ifdef DEBUG
	COMPILER := $(COMPILER) -g
endif

LINKER := $(COMPILER)

ifdef RELEASE
	COMPILER := $(COMPILER) -O3
	LINKER := $(LINKER) -Wl,--gc-sections,-s
endif


