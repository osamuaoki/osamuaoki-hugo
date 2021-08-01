PATH := $(CURDIR)/../../bin:$(PATH)
SRC = printpathx2 printpathx3
TARGET = $(addsuffix .log, $(SRC))
CLEAN  = 

all: $(TARGET)

printpathx%.log: printpathx%
	./printpathx$*|fold -s>$@

%.log: %.sh
	q $*

clean:
	-rm -f $(TARGET) 
	-rm -rf $(CLEAN)

.PHONY: all clean
