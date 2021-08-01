PATH := $(CURDIR)/../../bin:$(PATH)
SRC = gtk3-apt gtk3-dpkg gtk3-pkg-config gui
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
