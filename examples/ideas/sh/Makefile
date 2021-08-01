PATH := $(CURDIR)/../../bin:$(PATH)

# gpg require user input, thus building this part 
# via parent MAKEFILE is disabled.
# Initialize archive manually and create *.txt
# by manually touching up.

all:
	$(MAKE) gpg.log
	$(MAKE) hello-secret.log

%.log: %.sh
	r $*

clean:
	-rm -f hello.log
	-rm -f hello-secret.log gpg.log
	-rm -f hello.asc

