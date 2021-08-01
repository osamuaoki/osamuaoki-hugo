PATH := $(CURDIR)/../../bin:$(PATH)
SRC = gui-1 gui-1c gui-2 gui-2c gui-3 gui-3c
TARGET = $(addsuffix .log, $(SRC))
CLEAN  = gui-1 gui-2 gui-3 gui-1.c gui-2.c gui-3.c 

all: $(TARGET)

%.log: %.sh
	q $*

clean:
	-rm -f *.ldd *.nm *.s *.o
	-rm -f tmp.*
	-rm -f $(TARGET) gui
	-rm -rf $(CLEAN)

.PHONY: all clean
