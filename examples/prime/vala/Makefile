PATH := $(CURDIR)/../../bin:$(PATH)

all: prime.log
	$(MAKE) prime-test.log prime-perf1.log prime-perf2.log
	sed -ne '/# Overhead/,+13p' perf.report >perf.reportx

%.log: %.sh
	q $*
	sed -i 's#$(CURDIR)/#/full/path/to/#g' $*.log
clean:
	-rm -f *.log prime prime.c perf.*
