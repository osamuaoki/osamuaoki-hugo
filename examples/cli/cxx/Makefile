# buiuld always
# clean everything

PATH := $(CURDIR)/../../bin:$(PATH)

all: cli.log

%.log: %.sh
	q $*
clean:
	-rm -f cli cli.log

distclean: clean
.PHONY: all clean distclean

