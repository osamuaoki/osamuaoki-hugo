PATH := $(CURDIR)/../../bin:$(PATH)

all: fibo.log fibo-test.log strtol-test.log

%.log: %.sh
	q $*
clean:
	-rm -f *.log
	-rm -f fibo strtol-test
