#!/usr/bin/python
# vi:ts=4:sts=4:et
import sys, os, re

type = {}
perf = []

def tableline(section,size):
    if section == "(NONE)":
        sectionx = ""
    else:
        sectionx = section
    for i in range(0,4):
        if not (section in perf[i]):
            perf[i][section] = "N/A"
        else:
            perf[i][section] = perf[i][section].lstrip("0")
            if perf[i][section] == "":
                perf[i][section] = "0"
            else:
                perf[i][section] = "0x" + perf[i][section]
    print "|" + sectionx + " |" + type[section] + " |" + perf[0][section] + " |" +  perf[1][section]  + " |" + perf[2][section] + " |" +  perf[3][section] + " |" + size

for j in range(0,4):
    data = {}
    version = 0
    for i in range(0,5):
        line = sys.stdin.readline() # dummy
    for i in range(0,39):
        line1 = sys.stdin.readline()
        line2 = sys.stdin.readline()
        if line1[0:3] == "Key":
            break
        sec = line1[7:24].strip()
        if sec == "":
            sec = "(NONE)"
        type[sec] = line1[25:40].strip()
        data[sec] = line2[15:23]
        #print x.strip() + ": " + y.strip()
    for i in range(0,2):
        line = sys.stdin.readline() # dummy
    perf.append(data)

print '[cols="3,3,2,2,2,2,2", frame="topbot",options="header"]'
print "|====="
print "|section |type |`hello.o` | `hello-gdb.o` |`hello` | `hello-gdb` | `size`"
tableline("(NONE)","")
tableline(".interp","text")
tableline(".note.ABI-tag","text")
tableline(".note.gnu.build-i","text")
tableline(".dynsym","text")
tableline(".dynstr","text")
#tableline(".hash","text")
tableline(".gnu.hash","text")
tableline(".gnu.version","text")
tableline(".gnu.version_r","text")
tableline(".rela.dyn","text")
tableline(".rela.plt","text")
tableline(".init","text")
tableline(".plt","text")
tableline(".text","text")
tableline(".fini","text")
tableline(".rodata","text")
tableline(".eh_frame","text")
tableline(".eh_frame_hdr","text")
tableline(".dynamic","data")
tableline(".got","data")
tableline(".got.plt","data")
tableline(".data","data")
tableline(".jcr","data")
#tableline(".tm_clone_table","data")
tableline(".fini_array","data")
tableline(".init_array","data")
tableline(".bss","bss")
tableline(".comment","???")
tableline(".debug_info","???")
tableline(".debug_abbrev","???")
#tableline(".debug_loc","???")
tableline(".debug_aranges","???")
tableline(".debug_line","???")
tableline(".debug_str","???")
#tableline(".note.gnu.gold-ve","???")
tableline(".symtab","???")
tableline(".strtab","???")
tableline(".shstrtab","???")
print "|====="
