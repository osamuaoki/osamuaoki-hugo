PATH := $(CURDIR)/../../bin:$(PATH)

all: size.log size1.log

extra: size-gdb.log

%.log: %.sh
	q $*
clean:
	-rm -f size size-gdb
	-rm -f *.log
