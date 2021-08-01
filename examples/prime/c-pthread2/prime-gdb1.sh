p 'cat prime.1.gdb'
p 'gdb -batch -x prime.1.gdb' |\
  ./snip |\
  sed -e '/^19$/,/^1061$/d' -e '/^17$/s/^17$/... (snip)/'

