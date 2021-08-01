PATH := $(CURDIR)/../../bin:$(PATH)

all: hello.log hello-generic.log hello-simple.log

%.log: %.sh
	r $*
clean:
	-rm -f *.log
