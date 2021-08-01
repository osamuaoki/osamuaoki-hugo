PATH := $(CURDIR)/../../bin:$(PATH)

all: cp.log cp1.log cp2.log
	-rm -rf foo bar

extra: cp-gdb.log

%.log: %.sh
	q $*
clean:
	-rm -f cp foo bar cp-gdb
	-rm -f *.log
