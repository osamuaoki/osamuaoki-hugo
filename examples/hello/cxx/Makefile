PATH := $(CURDIR)/../../bin:$(PATH)

all: hello.log hello-s.log ldd.log nm.log nmfilt.log

nm.log nmfilt.log ldd.log: hello.log

%.log: %.sh
	q $*
clean:
	-rm -f hello hello.log hello-s.log hello.s ldd.log nm.log nmfilt.log
