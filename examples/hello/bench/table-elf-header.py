#!/usr/bin/python
# vi:ts=4:sts=4:et
import sys, os, re
def tableline4(item):
    print "|" + item + " 4+|" + perf[0][item]

def tableline2(item):
    print "|" + item + " 2+|" + perf[0][item] + " 2+|" + perf[2][item]

def tableline(item, unit):
    print "|" + item + unit + " |" + perf[0][item] + " |" +  perf[1][item]  + " |" + perf[2][item] + " |" +  perf[3][item]

perf = []

for j in range(0,4):
    data = {}
    version = 0
    for i in range(0,20):
        line = sys.stdin.readline()
        x, y = line.split(":")
        x = x.strip()
        if x == "Version" and version == 0:
            x = "Version (EI_VERSION)"
            version = 1
        elif x == "Version" and version == 1:
            x = "Version (e_version)"
        y = y.strip()
        if i > 9: 
            y = y.split("(")[0]
        data[x] = y.rstrip()
        #print x.strip() + ": " + y.strip()
    perf.append(data)

print '[cols="2,1,1,1,1", frame="topbot",options="header"]'
print "|====="
print "|Item |`hello.o` |`hello-gdb.o` |`hello` |`hello-gdb`"
tableline4("Magic")
tableline4("Class")
tableline4("Data")
tableline4("Version (EI_VERSION)")
tableline4("OS/ABI")
tableline4("ABI Version")
tableline2("Type")
tableline4("Machine")
tableline("Version (e_version)", "")
tableline("Entry point address", "")
tableline("Start of program headers", " (bytes into file)")
tableline("Start of section headers", " (bytes into file)")
tableline("Flags", "")
tableline("Size of this header", " (bytes)")
tableline("Size of program headers", " (bytes)")
tableline("Number of program headers", "")
tableline("Size of section headers", " (bytes)")
tableline("Number of section headers", "")
tableline("Section header string table index", "")
print "|====="

