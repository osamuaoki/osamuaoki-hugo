# build always
# clean everything

all:
	$(MAKE) -C c $@
	$(MAKE) -C cxx $@
	$(MAKE) -C sh $@
	$(MAKE) -C lua $@
	$(MAKE) -C python $@
	$(MAKE) -C python_cliapp $@
	$(MAKE) -C perl $@
	$(MAKE) -C vala $@

%:
	$(MAKE) -C c $@
	$(MAKE) -C cxx $@
	$(MAKE) -C sh $@
	$(MAKE) -C lua $@
	$(MAKE) -C python $@
	$(MAKE) -C python_cliapp $@
	$(MAKE) -C perl $@
	$(MAKE) -C vala $@

.PHONY: all clean distclean

