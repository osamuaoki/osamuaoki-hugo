PATH := $(CURDIR)/../../bin:$(PATH)

all: fibo-test.log

%.log: %.sh
	r $*

clean:
	-rm -f *.log

