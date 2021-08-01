#!/bin/sh
p 'grep -e "^Description\|^Name\|^Requires" \
   $(dpkg -L libglib2.0-dev|grep -e "/pkgconfig/")| \
   sed -ne "s/^.*\/pkgconfig\//.../p"'
