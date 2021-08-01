# build everything
# clean everything

PATH := $(CURDIR)/../../bin:$(PATH)

all: cli.log cli-assert.log cli-log.log cli-log2.log

%.log: %.sh
	r $*
clean:
	-rm -f *.log

distclean: clean

.PHONY: all clean distclean

