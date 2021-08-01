PATH := $(CURDIR)/../../bin:$(PATH)

all:
	./table-elf-header.py <../c/elf-header.txt >elf-header.txt
	./table-elf-section.py <../c/elf-section.txt >elf-section.txt


clean:
	-rm -f *.txt
