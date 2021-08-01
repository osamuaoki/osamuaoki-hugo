#!/bin/sh
p 'gcc -Wall `pkg-config --cflags --libs lua5.1` -c dump.c'
p 'gcc -Wall `pkg-config --cflags --libs lua5.1` -c luastack.c'
p 'gcc -Wall `pkg-config --cflags --libs lua5.1` dump.o luastack.o -o luastack'
p './luastack'
