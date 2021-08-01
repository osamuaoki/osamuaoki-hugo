#!/bin/sh
p 'gcc -Wall `pkg-config --cflags --libs gtk+-3.0` -o gui gui.c'
