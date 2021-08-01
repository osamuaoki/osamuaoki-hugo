#!/usr/bin/python
# vi:ts=4:sts=4:et
import sys, os, re
def read():
    real = sys.stdin.readline()
    user = sys.stdin.readline()
    syx  = sys.stdin.readline()
    return(real[:-1],user[:-1],syx[:-1])

print "|Program| real(2^16) | user(2^16) | sys(2^16) | real(2^20) | user(2^20) | sys(2^20)"
t1=read()
print "|Shell| "+t1[0]+"|"+t1[1]+"|"+t1[2]+"| -- | -- | --"
t1=read()
t2=read()
print "|Python| "+t1[0]+"|"+t1[1]+"|"+t1[2]+"|"+t2[0]+"|"+t2[1]+"|"+t2[2]
t1=read()
t2=read()
print "|Lua| "+t1[0]+"|"+t1[1]+"|"+t1[2]+"|"+t2[0]+"|"+t2[1]+"|"+t2[2]
t2=read()
print "|Lua (for ... in)| -- | -- | -- |"+t2[0]+"|"+t2[1]+"|"+t2[2]
t1=read()
t2=read()
print "|Perl| "+t1[0]+"|"+t1[1]+"|"+t1[2]+"|"+t2[0]+"|"+t2[1]+"|"+t2[2]
t1=read()
t2=read()
print "|C (array)| "+t1[0]+"|"+t1[1]+"|"+t1[2]+"|"+t2[0]+"|"+t2[1]+"|"+t2[2]
t1=read()
t2=read()
print "|C (list)| "+t1[0]+"|"+t1[1]+"|"+t1[2]+"|"+t2[0]+"|"+t2[1]+"|"+t2[2]
t1=read()
t2=read()
print "|Vala (glib)| "+t1[0]+"|"+t1[1]+"|"+t1[2]+"|"+t2[0]+"|"+t2[1]+"|"+t2[2]
t1=read()
t2=read()
print "|Vala (gee)| "+t1[0]+"|"+t1[1]+"|"+t1[2]+"|"+t2[0]+"|"+t2[1]+"|"+t2[2]

