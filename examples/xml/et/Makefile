PATH := $(CURDIR)/../../bin:$(PATH)

all: download.log search-xpath.log kanji.log

download.log jouyou.xml:
	r download
	
search-xpath.log: jouyou.xml
	r search-xpath

kanji.log: jouyou.xml
	q kanji

clean:
	-rm -f *.log
	-rm -f jouyou.xml

distclean: clean

.PHONY: all clean distclean

