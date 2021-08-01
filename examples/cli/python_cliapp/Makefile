# build always
# clean everything

PATH := $(CURDIR)/../../bin:$(PATH)

all: cli.log

%.log: %.sh
	r $*
clean:
	-rm -f cli.log

distclean: clean

.PHONY: all clean distclean

