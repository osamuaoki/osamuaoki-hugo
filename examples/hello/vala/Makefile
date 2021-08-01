PATH := $(CURDIR)/../../bin:$(PATH)

all: hello-1.log hello-1c.log hello-2.log hello-2c.log hello-3.log hello-3c.log

%.log: %.sh
	q $*
clean:
	-rm -f *.log *.ldd *.nm *.c
	-rm -f hello-1 hello-2 hello-3
