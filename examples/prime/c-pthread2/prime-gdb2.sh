p 'cat prime.2.gdb'
p 'gdb -batch -x prime.2.gdb prime-gdb' | \
   sed -e '/^19$/,/^1061$/d' -e '/^17$/s/^17$/... (snip)/'
