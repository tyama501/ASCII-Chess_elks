#BASEDIR=..
BASEDIR=$(TOPDIR)/elkscmd

###############################################################################
#
# Include standard packaging commands.

include $(BASEDIR)/Makefile-rules

###############################################################################

LOCALFLAGS = -DELKS=1

PRGS = achess

all: $(PRGS)

achess: src/chess3.o
	$(LD) $(LDFLAGS) -o achess src/chess3.o $(LDLIBS)

install: $(PRGS)
	$(INSTALL) $(PRGS) $(DESTDIR)/bin

clean:
	rm -f $(PRGS) src/*.o
