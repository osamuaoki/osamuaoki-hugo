PATH := $(CURDIR)/../../bin:$(PATH)
SRC = printpath2 printpath3
TARGET = $(addsuffix .log, $(SRC))
CLEAN  = 

all: $(TARGET)

#printpath%.log: printpath%
#	./printpath$*|sed -e 's,$(CURDIR),/path/to/curdir/,g'| fold -s>$@

%.log: %.sh
	r $*

clean:
	-rm -f $(TARGET) 
	-rm -rf $(CLEAN)

.PHONY: all clean
