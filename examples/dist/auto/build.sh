#!/bin/sh
cd hello >/dev/null
p './configure --prefix=/usr'
p 'make'
p 'DESTDIR=./debian/tmp make install'
p '# now run it'
p './debian/tmp/usr/bin/hello'
