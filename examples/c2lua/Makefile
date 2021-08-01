# build always
# clean everything

PATH := $(CURDIR)/../bin:$(PATH)

all: luastack.log luahost.log

luahost.log: dump.o

%.log: %.sh
	q $*

clean:
	-rm -f *.ldd *.nm *.s *.o
	-rm -f luastack luahost
	-rm -f *.log tmp.*

distclean: clean

.PHONY: all clean distclean
