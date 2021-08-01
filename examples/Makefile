# build: update data and build new html
# clean only non-timeconsuming (leave html)
# distclean everything
# 

TERM = dumb
SHELL	= /bin/sh
PATH	:= (CURDIR)/bin:$(PATH) 

export SHELL PATH TERM

all:
	$(MAKE) data


data:
	$(MAKE) -C hello all
	$(MAKE) -C gcc all
	$(MAKE) -C cli all
	$(MAKE) -C lib all
	$(MAKE) -C gui all
	$(MAKE) -C c2lua all
	$(MAKE) -C dist all
	$(MAKE) -C sqlite all
	$(MAKE) -C ideas all
	$(MAKE) -C prime all
	$(MAKE) -C fibo all
	$(MAKE) -C stat all
	$(MAKE) -C process all
	$(MAKE) -C python all

%:
	$(MAKE) -C hello $@
	$(MAKE) -C gcc $@
	$(MAKE) -C cli $@
	$(MAKE) -C lib $@
	$(MAKE) -C gui $@
	$(MAKE) -C c2lua $@
	$(MAKE) -C dist $@
	$(MAKE) -C sqlite $@
	$(MAKE) -C ideas $@
	$(MAKE) -C prime $@
	$(MAKE) -C fibo $@
	$(MAKE) -C stat $@
	$(MAKE) -C process $@
	$(MAKE) -C python $@

distclean: clean

