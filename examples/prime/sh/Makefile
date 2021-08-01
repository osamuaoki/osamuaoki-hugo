PATH := $(CURDIR)/../../bin:$(PATH)

all: prime-test.log

%.log: %.sh
	r $*

clean:
	-rm -f *.log

