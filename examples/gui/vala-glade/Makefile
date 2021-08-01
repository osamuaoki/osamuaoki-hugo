PATH := $(CURDIR)/../../bin:$(PATH)
BIN = $(addprefix gui-, 1 2 3 4 5)
SRC = $(BIN) $(addsuffix c, $(BIN))
TARGET = $(addsuffix .log, $(SRC))
CLEAN  = $(BIN) $(addsuffix .c, $(BIN))

all: $(TARGET)

%.log: %.sh
	q $*

clean:
	-rm -f *.ldd *.nm *.s *.o
	-rm -f tmp.*
	-rm -f $(TARGET)
	-rm -rf $(CLEAN)

.PHONY: all clean
