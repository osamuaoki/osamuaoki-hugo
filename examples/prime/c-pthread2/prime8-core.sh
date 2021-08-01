#p "gcc -g -Wall -D_FORTIFY_SOURCE=2 -O2 -fstack-protector-all -lpthread -o prime8-gdb prime8.c"
p "gcc -g -Wall -lpthread -o prime8-gdb prime8.c"
echo '$ ulimit -c unlimited'
ulimit -c unlimited
p './prime8-gdb 1090'
p 'ls -l core'

./gdbecho <prime8-core.cmd.in >prime8-core.cmd
p 'gdb -batch -x prime8-core.cmd prime8-gdb core' |\
  sed -e 's/\$ gdb -batch -x prime8-core.cmd.*$/\$ gdb -q prime8-gdb core/'

