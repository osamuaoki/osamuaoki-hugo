#!/bin/sh
grep -e "ELF ..-bit LSB executable" list.txt | cut -s -d: -f1 >elf.txt
