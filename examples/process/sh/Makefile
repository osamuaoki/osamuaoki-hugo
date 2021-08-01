PATH := $(CURDIR)/../../bin:$(PATH)
LOGS =  $(patsubst %.sh,%.log,$(wildcard *.sh))
# set to customize
EXTRA = signal.log 
CLEAN = 

TARGET = $(filter-out $(EXTRA),$(LOGS))

all:  $(TARGET)

%.log: %.sh
	q $*

clean:
	-rm -f $(LOGS)
	-rm -f $(CLEAN)

.PHONY: all clean
