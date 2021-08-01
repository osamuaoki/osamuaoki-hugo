PATH := $(CURDIR)/../../bin:$(PATH)
LOGS =  $(patsubst %.sh,%.log,$(wildcard *.sh))
# set to customize
EXTRA = 
CLEAN = upper upper-v

TARGET = $(filter-out $(EXTRA),$(LOGS))

all:  $(TARGET)

%.log: %.sh
	q $*
	sed -i 's#$(CURDIR)/#/full/path/to/#g' $*.log

clean:
	-rm -f $(LOGS)
	-rm -f $(CLEAN)

.PHONY: all clean
