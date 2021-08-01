PATH := $(CURDIR)/../../bin:$(PATH)

all: hello.log

%.log: %.sh
	r $*

clean:
	-rm -f *.log

