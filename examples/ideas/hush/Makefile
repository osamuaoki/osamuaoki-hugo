PATH := $(CURDIR)/../../bin:$(PATH)

# gpg require user input, thus building this part 
# via parent MAKEFILE is disabled.
# Initialize archive manually and create *.txt
# by manually touching up.

all:
	cp -f test.conf.in test.conf
	$(MAKE) md5add.log
	$(MAKE) md5chk.log
	$(MAKE) md5mod.log

%.log: %.sh
	r $*

clean: 
	-rm -f *.log test.conf

