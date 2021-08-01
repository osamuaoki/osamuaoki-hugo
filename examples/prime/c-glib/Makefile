PATH := $(CURDIR)/../../bin:$(PATH)

all: prime.log prime-test.log

%.log: %.sh
	q $*
clean:
	-rm -f *.log prime
