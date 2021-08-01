#!/bin/sh
p 'gcc -Wall -c math-main.c'
p 'gcc -Wall -c sindeg.c'
p 'gcc -Wall -o math-main math-main.o sindeg.o -lm'
p './math-main'
