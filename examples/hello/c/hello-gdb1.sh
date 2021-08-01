./gdbecho <hello1.cmd.in >hello1.cmd
p 'gdb -x hello1.cmd hello-gdb' |\
sed -e 's/\$ gdb -.*$/\$ gdb hello-gdb/'
p ''
