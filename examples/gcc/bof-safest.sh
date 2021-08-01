#!/bin/sh
p 'gcc -fstack-protector-all -o bof-safest bof.c'
p './bof-safest "0123456789"'
