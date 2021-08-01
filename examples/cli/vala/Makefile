# build always
# clean everything

PATH := $(CURDIR)/../../bin:$(PATH)

all: cli-1.log cli-1c.log cli-2.log cli-2c.log cli-3.log cli-3c.log

%.log: %.sh
	q $*
clean:
	-rm -f *.log *.c
	-rm -f cli-1 cli-2 cli-3

distclean: clean

.PHONY: all clean distclean

