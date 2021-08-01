p "cat prime9.patch"
p "cp prime8.c prime9.c"
p "patch -p0 prime9.c <prime9.patch"
p "gcc -g -Wall -lpthread -o prime9-gdb prime9.c"
p './prime9-gdb "1090">/dev/null; echo $?'
p './prime9-gdb "4"'
p './prime9-gdb "3"' | head
echo " ... (snip)"
