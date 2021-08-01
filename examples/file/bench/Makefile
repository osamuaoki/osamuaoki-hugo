PATH := $(CURDIR)/../../bin:$(PATH)

all:
	sed -e 's/ *#.*$$//' ../size-char/size1.log	|grep -v '^ *$$' | sed -n '4,$$p' >p0.txt
	sed -e 's/ *#.*$$//' ../size-block/size1.log	|grep -v '^ *$$' | sed -n '4,$$p' >>p0.txt
	sed -e 's/ *#.*$$//' ../size-lseek/size1.log	|grep -v '^ *$$' | sed -n '4,$$p' >>p0.txt
	sed -e 's/ *#.*$$//' ../size-stat/size1.log	|grep -v '^ *$$' | sed -n '4,$$p' >>p0.txt
	./table-perf4.py <p0.txt >perf0.txt

	sed -e 's/ *#.*$$//' ../cp-char/cp1.log		|grep -v '^ *$$' | sed -n '3,$$p' >p1.txt
	sed -e 's/ *#.*$$//' ../cp-block/cp1.log	|grep -v '^ *$$' | sed -n '3,$$p' >>p1.txt
	sed -e 's/ *#.*$$//' ../cp-blockbig/cp1.log	|grep -v '^ *$$' | sed -n '3,$$p' >>p1.txt
	sed -e 's/ *#.*$$//' ../cp-mmap-memcpy/cp1.log	|grep -v '^ *$$' | sed -n '3,$$p' >>p1.txt
	sed -e 's/ *#.*$$//' ../cp-mmap-write/cp1.log	|grep -v '^ *$$' | sed -n '3,$$p' >>p1.txt
	./table-perf5.py <p1.txt >perf1.txt

	sed -e 's/ *#.*$$//' ../cp-char/cp2.log		|grep -v '^ *$$' | sed -n '3,$$p' >p2.txt
	sed -e 's/ *#.*$$//' ../cp-block/cp2.log	|grep -v '^ *$$' | sed -n '3,$$p' >>p2.txt
	sed -e 's/ *#.*$$//' ../cp-blockbig/cp2.log	|grep -v '^ *$$' | sed -n '3,$$p' >>p2.txt
	sed -e 's/ *#.*$$//' ../cp-mmap-memcpy/cp2.log	|grep -v '^ *$$' | sed -n '3,$$p' >>p2.txt
	sed -e 's/ *#.*$$//' ../cp-mmap-write/cp2.log	|grep -v '^ *$$' | sed -n '3,$$p' >>p2.txt
	./table-perf5.py <p2.txt >perf2.txt



clean:
	-rm -f *.txt
