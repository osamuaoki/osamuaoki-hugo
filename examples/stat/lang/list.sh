#!/bin/sh
file /bin/* /sbin/* /usr/bin/* /usr/sbin/* |\
sed -e 's/BuildID\[sha1\].*//' |\
grep -v '/symbolic link/' |\
sort - >list.txt
