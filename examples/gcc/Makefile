PATH := $(CURDIR)/../bin:$(PATH)

all: bof-fortify.log bof-safe.log bof-safest.log bof-unsafe.log gcc-version.log \
	string-array.log string-const-pointer.log string-pointer.log string-arrayS.log string-pointerS.log

%.log: %.sh
	q $*
clean:
	-rm -f bof-fortify.log bof-safe.log bof-safest.log bof-unsafe.log gcc-version.log string-array.log string-const-pointer.log string-pointer.log
	-rm -f bof-fortify bof-safe bof-safest bof-unsafe string-array string-const-pointer string-pointer
	-rm -f string-arrayS.log string-pointerS.log string-array.s string-pointer.s
