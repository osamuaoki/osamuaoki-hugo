#!/bin/sh
p 'gcc -fstack-protector --param=ssp-buffer-size=4 -o bof-safe bof.c'
p './bof-safe "0123456789"'
