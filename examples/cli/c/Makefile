# build always
# clean everything

PATH := $(CURDIR)/../../bin:$(PATH)

all: cli_s.log cli_l.log cli-log.log cli-log-no.log cli-assert.log cli-assert-no.log
	-rm -f core

%.log: %.sh
	q $*
clean:
	-rm -f cli_s cli_l cli-log cli-log-no cli-assert cli-assert-no
	-rm -f *.log core

distclean: clean

.PHONY: all clean distclean

