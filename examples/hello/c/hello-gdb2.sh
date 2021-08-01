p 'COLUMNS=80 dpkg -l libc6-dbg:amd64'
./gdbecho <hello2.cmd.in >hello2.cmd
p 'gdb -batch -x hello2.cmd hello-gdb 2>&1' |\
sed -e 's/\$ gdb -batch -.*$/\$ gdb -q hello-gdb/'
p ''
