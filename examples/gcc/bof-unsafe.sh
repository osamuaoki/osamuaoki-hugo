#!/bin/sh
p 'gcc -fno-stack-protector -o bof-unsafe bof.c'
p './bof-unsafe "0123456789"'
