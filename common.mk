#PWD := $(warning "Shelling...")$(shell pwd | sed "s/.*\///")
PWD := $(shell pwd | sed "s/.*\///")

../$(PWD).dir.o : $(foreach dir,$(DIRS),$(dir).dir.o) $(foreach obj,$(OBJS),$(obj).o)
	${BUNDLER} -o $@ $+

%.dir.o : force
	cd $(*F); make -r
%.o : %.cpp %.h
	${COMPILER} -c $<
%.o : %.cpp
	${COMPILER} -c $<
moc_%.cpp : %.h
	${MOC} -o $@ $<

clean:
	#find $(SRCDIR) -type f -name '*.o'
	#find $(BINDIR) -type f
force:
	true

