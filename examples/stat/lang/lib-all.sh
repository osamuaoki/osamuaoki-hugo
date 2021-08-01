#!/bin/sh
cat elf.txt | xargs -n1 ldd |\
sed -e "s/=>.*$//" -e "s/([^(]*)//g" - |\
sort |uniq -c | sort -nr |\
sed -e "s/^\(........\)\(.*\)$/|\2|\1/" >lib-all.txt
