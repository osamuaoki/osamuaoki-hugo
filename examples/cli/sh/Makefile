# build always
# clean everything

PATH := $(CURDIR)/../../bin:$(PATH)

all: cli-assert.log cli-log.log

%.log: %.sh
	q $*
clean:
	-rm -f *.log

distclean: clean

.PHONY: all clean distclean

