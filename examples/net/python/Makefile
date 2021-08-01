PATH := $(CURDIR)/../../bin:$(PATH)
LOGS =  $(patsubst %.sh,%.log,$(wildcard *.sh))
# set to customize
EXTRA =
CLEAN = $(EXTRA)

TARGET = $(filter-out $(EXTRA),$(LOGS))

all: $(EXTRA)
	$(MAKE) $(TARGET)

%.log: %.sh
	q $*

clean:
	-rm -f $(LOGS)
	-rm -f $(CLEAN)

.PHONY: all clean
