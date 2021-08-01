p '/usr/lib/gcc/x86_64-linux-gnu/4.7/cc1 --help |grep "language C:" -A1'
p '/usr/lib/gcc/x86_64-linux-gnu/4.7/cc1 --help=C' |head -10; echo "   ... (snip)"
p '/usr/lib/gcc/x86_64-linux-gnu/4.7/collect2 --help'|head -10; echo "   ... (snip)"
