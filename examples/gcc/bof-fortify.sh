#!/bin/sh
p 'gcc -D_FORTIFY_SOURCE=2 -O2 -o bof-fortify bof.c'
p './bof-fortify "0123456789"'
