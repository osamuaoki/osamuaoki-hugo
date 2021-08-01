PATH := $(CURDIR)/../../bin:$(PATH)

all:
	$(MAKE) prime5.log
	$(MAKE) prime6.log
	$(MAKE) prime7.log
	$(MAKE) prime8.log
	$(MAKE) prime5-test.log
	$(MAKE) prime6-test.log
	$(MAKE) prime7-test.log
	$(MAKE) prime8-test.log
	$(MAKE) prime-extra.log
	$(MAKE) prime8-bug.log

extra: prime-extra.log

%.log: %.sh
	q $*
	sed -i 's#$(CURDIR)/#/full/path/to/#g' $*.log
clean:
	-rm -f *.log prime
