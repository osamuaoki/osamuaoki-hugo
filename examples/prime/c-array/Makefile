PATH := $(CURDIR)/../../bin:$(PATH)

all: prime.log prime-test.log

%.log: %.sh
	q $*
	sed -i 's#$(CURDIR)/#/full/path/to/#g' $*.log
clean:
	-rm -f *.log prime
