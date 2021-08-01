PATH := $(CURDIR)/../../bin:$(PATH)

all:
	$(MAKE) hello.log hello-gdb.log hello-gdbo.log
	$(MAKE) stat
	$(MAKE) gdbx


stat:
	$(MAKE) hello-s.log ldd.log nm.log
	$(MAKE) hello-hd.log hello-readelf-a.log hello-objdump-s.log hello-objdump-d.log
	$(MAKE) hello-readelf-h.log hello-readelf-l.log hello-readelf-S.log 
	$(MAKE) collect2.log hello-size.log hello-gdb-hd.log
	$(MAKE) hello-gdb-readelf-h.log hello-gdb-readelf-l.log  hello-gdb-readelf-S.log hello-gdb-readelf-xtext.log 
	$(MAKE) hello-gdb-readelf-a.log  hello-gdb-readelf-ws.log hello-gdb-readelf-wL.log 
	$(MAKE) hello-gdb-objdump-s.log  hello-gdb-objdump-d.log hello-gdbo-objdump-d.log hello-gdbo-objdump-S.log 
	$(MAKE) hello-gdb-strace.log hello-gdb-strace-c.log hello-gdb-strace-e.log hello-gdb-ltrace.log hello-gdb-ltrace-c.log


gdb:	hello-gdb.log
	$(MAKE) hello-gdb1.log hello-gdb2.log

gdbx:	gdb
	sed -n '1,/(gdb) # pos1/p' hello-gdb1.log|grep -v '(gdb) # pos' >hello-gdb1.1.log
	sed -n '/(gdb) # pos1/,/(gdb) # pos2/p' hello-gdb1.log|grep -v '(gdb) # pos' >hello-gdb1.2.log
	sed -n '/(gdb) # pos2/,/(gdb) # pos3/p' hello-gdb1.log|grep -v '(gdb) # pos' >hello-gdb1.3.log
	sed -n '1,/(gdb) # pos1/p' hello-gdb2.log|grep -v '(gdb) # pos' >hello-gdb2.1.log
	sed -n '/(gdb) # pos1/,/(gdb) # pos2/p' hello-gdb2.log|grep -v '(gdb) # pos' >hello-gdb2.2.log
	sed -n '/(gdb) # pos2/,/(gdb) # pos3/p' hello-gdb2.log|grep -v '(gdb) # pos' >hello-gdb2.3.log
	sed -n '/(gdb) # pos3/,/(gdb) # pos4/p' hello-gdb2.log|grep -v '(gdb) # pos' >hello-gdb2.4.log
	sed -n '/(gdb) # pos4/,/(gdb) # pos5/p' hello-gdb2.log|grep -v '(gdb) # pos' >hello-gdb2.5.log
	sed -n '/(gdb) # pos5/,/(gdb) # pos6/p' hello-gdb2.log|grep -v '(gdb) # pos' >hello-gdb2.6.log
	sed -n '/(gdb) # pos6/,/(gdb) # pos7/p' hello-gdb2.log|grep -v '(gdb) # pos' >hello-gdb2.7.log

nm.log ldd.log: hello.log

%.log: %.sh
	r $*
clean:
	-rm -f hello hello-gdb
	-rm -f *.o *.s *.log *.txt *.cmd

.PHONY: all stat gdb gdbx clean

