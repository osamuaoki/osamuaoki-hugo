PATH := $(CURDIR)/../../bin:$(PATH)

all: prime-test.log prime-perf1.log prime-perf2.log
	sed -ne '/# Overhead/,+16p' perf.report >perf.reportx

%.log: %.sh
	q $*

clean:
	-rm -f *.log perf.*

