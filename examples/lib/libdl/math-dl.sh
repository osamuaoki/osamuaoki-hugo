#!/bin/sh
p 'gcc -Wall -rdynamic -omath-dl math-dl.c -ldl'
p './math-dl'
