PATH := $(CURDIR)/../../bin:$(PATH)
BIN = $(addprefix sql-, 1 2 3 4)
SRC = $(BIN)
TARGET = $(addsuffix .log, $(SRC))
CLEAN  = private.db

all: $(TARGET)

%.log: %.sh
	q $*

sql-2.log: sql-1.log

sql-3.log: sql-2.log

sql-4.log: sql-3.log

clean:
	-rm -f tmp.*
	-rm -f $(TARGET)
	-rm -rf $(CLEAN)

.PHONY: all clean
