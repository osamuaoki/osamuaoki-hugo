PATH := $(CURDIR)/../../bin:$(PATH)

all:
	sed -n -e 's/^user \|^sys \|^real //p' ../sh/prime-test.log >time.txt
	sed -n -e 's/^user \|^sys \|^real //p' ../python/prime-test.log >>time.txt
	sed -n -e 's/^user \|^sys \|^real //p' ../lua/prime-test.log >>time.txt
	sed -n -e 's/^user \|^sys \|^real //p' ../perl/prime-test.log >>time.txt
	sed -n -e 's/^user \|^sys \|^real //p' ../c-array/prime-test.log >>time.txt
	sed -n -e 's/^user \|^sys \|^real //p' ../c-list/prime-test.log >>time.txt
	sed -n -e 's/^user \|^sys \|^real //p' ../vala/prime-test.log >>time.txt
	sed -n -e 's/^user \|^sys \|^real //p' ../vala-gee/prime-test.log >>time.txt
	./table.py <time.txt >time-table.txt
	sed -n -e 's/^user \|^sys \|^real //p' ../c-pthread/prime5-test.log >time1.txt
	sed -n -e 's/^user \|^sys \|^real //p' ../c-pthread/prime6-test.log >>time1.txt
	sed -n -e 's/^user \|^sys \|^real //p' ../c-pthread/prime7-test.log >>time1.txt
	sed -n -e 's/^user \|^sys \|^real //p' ../c-pthread/prime8-test.log >>time1.txt
	./table1.py <time1.txt >time-table1.txt
	sed -e 's/ *#.*$$//' ../c-list/prime-perf1.log   |grep -v '^ *$$' | sed -n '3,$$p' >perf0.txt
	sed -e 's/ *#.*$$//' ../vala-gee/prime-perf1.log |grep -v '^ *$$' | sed -n '3,$$p' >>perf0.txt
	sed -e 's/ *#.*$$//' ../python/prime-perf1.log   |grep -v '^ *$$' | sed -n '3,$$p' >>perf0.txt
	sed -e 's/ *#.*$$//' ../vala/prime-perf1.log     |grep -v '^ *$$' | sed -n '3,$$p' >>perf0.txt
	./table-perf.py <perf0.txt >perf.txt


clean:
	-rm -f *.txt
