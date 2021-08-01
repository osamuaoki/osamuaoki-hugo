#!/bin/sh
p 'gcc -Wall `pkg-config --cflags --libs lua5.1` -c average.c'
p 'gcc -Wall `pkg-config --cflags --libs lua5.1` -c luahost.c'
p 'gcc -Wall `pkg-config --cflags --libs lua5.1` dump.o average.o \
    luahost.o -o luahost'
p 'export SMALL'
p 'SMALL="NO"'
p './luahost script.lua'
p 'SMALL="YES"'
p './luahost script.lua'

