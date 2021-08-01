#!/usr/bin/python
# vi:ts=4:sts=4:et
import sys, os, re
def read():
    real = sys.stdin.readline()
    user = sys.stdin.readline()
    syx  = sys.stdin.readline()
    return(real[:-1],user[:-1],syx[:-1])

print "|Program| real(2^20) | user(2^20) | sys(2^20) | real(2^24) | user(2^24) | sys(2^24)"
t1=read()
t2=read()
print "|`prime5.c`| "+t1[0]+"|"+t1[1]+"|"+t1[2]+"|"+t2[0]+"|"+t2[1]+"|"+t2[2]
t1=read()
t2=read()
print "|`prime6.c`| "+t1[0]+"|"+t1[1]+"|"+t1[2]+"|"+t2[0]+"|"+t2[1]+"|"+t2[2]
t1=read()
t2=read()
print "|`prime7.c`| "+t1[0]+"|"+t1[1]+"|"+t1[2]+"|"+t2[0]+"|"+t2[1]+"|"+t2[2]
t1=read()
t2=read()
print "|`prime8.c`| "+t1[0]+"|"+t1[1]+"|"+t1[2]+"|"+t2[0]+"|"+t2[1]+"|"+t2[2]
