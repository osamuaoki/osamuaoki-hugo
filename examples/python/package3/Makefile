PATH := $(CURDIR)/../../bin:$(PATH)
LOGS =  $(patsubst %.sh,%.log,$(wildcard *.sh))
# set to customize
EXTRA =
CLEAN = $(EXTRA)

TARGET = $(filter-out $(EXTRA),$(LOGS))

all: $(EXTRA)
	$(MAKE) install
	$(MAKE) fridge-rm.log

install:
	$(MAKE) fridge-py.log
	$(MAKE) fridge-ls1.log
	$(MAKE) fridge-setup.log
	$(MAKE) fridge-ls2.log
	$(MAKE) fridge-copy.log

%.log: %.sh
	q $*

clean:
	-rm -f $(LOGS)
	-rm -f $(CLEAN)
	-rm -rf fridge/dist fridge/MANIFEST
	-rm -rf dist

.PHONY: all clean install
