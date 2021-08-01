#!/bin/sh
:>lang.stat
echo "| ELF executable (all)      | $(grep "ELF ..-bit LSB executable" lang.txt |wc -l)" >>lang.stat
echo "| ELF executable (set*id)      | $(grep "set.id.*ELF ..-bit LSB executable" lang.txt |wc -l)" >>lang.stat
echo "| ELF executable (linked to libc)     | $(cat elf.txt | xargs -n1 ldd | grep "=>" | grep "libc\.so" |wc -l)" >>lang.stat
echo "| ELF executable (linked to libstdc\++ = C++)| $(cat elf.txt | xargs -n1 ldd | grep "=>" | grep "libstdc++\.so" |wc -l)" >>lang.stat
echo "| ELF executable (linked to libX11 = X)  | $(cat elf.txt | xargs -n1 ldd | grep "=>" |grep "libX11\.so" |wc -l)" >>lang.stat
echo "| ELF executable (linked to gobject = GNOME)  | $(cat elf.txt | xargs -n1 ldd | grep "=>" |grep "libgobject-.\..\.so" |wc -l)" >>lang.stat
echo "| ELF executable (linked to libQtCore = KDE)       | $(cat elf.txt | xargs -n1 ldd | grep "=>" |grep "libQtCore\.so" |wc -l)" >>lang.stat
echo "| ELF executable (linked to libncurses)  | $(cat elf.txt | xargs -n1 ldd | grep "=>" |grep "libncurses\.so" |wc -l)" >>lang.stat
echo "| POSIX shell script        | $(grep "^POSIX shell script" lang.txt |wc -l       )" >>lang.stat
echo "| Perl script               | $(grep "^Perl script" lang.txt |wc -l              )" >>lang.stat
echo "| Python script             | $(grep "^Python script" lang.txt |wc -l            )" >>lang.stat
echo "| Bash shell script         | $(grep "^Bourne-Again shell script" lang.txt |wc -l)" >>lang.stat
echo "| Ruby script               | $(grep "^Ruby script" lang.txt |wc -l              )" >>lang.stat
echo "| Lua script                | $(grep "^Lua script" lang.txt |wc -l               )" >>lang.stat
#
