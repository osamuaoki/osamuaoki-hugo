PATH := $(CURDIR)/../../bin:$(PATH)

all: lang.stat lib.txt

list.txt:
	./list.sh

lang.txt: list.txt
	./lang.sh

elf.txt: list.txt
	./elf.sh

lang.stat: lang.txt elf.txt
	./lang.stat.sh

lib-all.txt: list.txt
	./lib-all.sh

lib.txt: lib-all.txt
	./lib.sh

clean:
	-rm -f *.log

reset: clean
	-rm -f lang.stat *.txt
