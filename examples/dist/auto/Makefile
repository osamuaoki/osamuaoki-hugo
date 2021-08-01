PATH := $(CURDIR)/../../bin:$(PATH)

all:
	$(MAKE) list.log
	$(MAKE) autoscan.log
	$(MAKE) autoreconf.log
	$(MAKE) configure-h.log
	$(MAKE) build.log

%.log: %.sh
	q $*

clean:
	-$(MAKE) -C hello maintainer-clean
	-cd hello;rm -f aclocal.m4 config.h.in configure configure.scan depcomp install-sh Makefile.in missing autoscan.log
	rm -f *.log tmp.*
	-rm -rf hello/debian 

.PHONY: all clean
