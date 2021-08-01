./gdbecho <prime8.cmd.in >prime8.cmd
p 'gdb -batch -x prime8.cmd' |\
  grep -v -e "^\[New" -e "^\[Thread" - | \
  sed "/^Using host libthread_db library/a \
   ... (snip thread dialog)" |\
sed -e 's/\$ gdb -batch -.*$/\$ gdb -q/'
