PATH := $(CURDIR)/../../bin:$(PATH)

all:
	$(MAKE) prime-alt.log
	$(MAKE) prime.log
	$(MAKE) prime-test.log
	$(MAKE) prime-all.log
	$(MAKE) prime-perf1.log
	$(MAKE) prime-perf2.log
	sed -ne '/# Overhead/,+8p' perf.report >perf.reportx

extra: prime-extra.log



%.log: %.sh
	q $*
	sed -i 's#$(CURDIR)/#/full/path/to/#g' $*.log
clean:
	-rm -f *.log prime[0-4] prime.c prime[0-4].[cs] prime
	-rm -f perf.*
