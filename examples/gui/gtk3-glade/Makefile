PATH := $(CURDIR)/../../bin:$(PATH)
SRC = gui
TARGET = $(addsuffix .log, $(SRC))
CLEAN  = 

all: $(TARGET)

%.log: %.sh
	q $*

clean:
	-rm -f *.ldd *.nm *.s *.o
	-rm -f tmp.*
	-rm -f $(TARGET) gui
	-rm -rf $(CLEAN)

.PHONY: all clean
