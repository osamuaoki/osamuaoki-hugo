p "gcc -g -Wall -lpthread -o prime10-gdb prime10.c"
p './prime10-gdb "1090">/dev/null; echo $?'
p './prime10-gdb "3"'
p './prime10-gdb "4"'
p './prime10-gdb "5"'
p './prime10-gdb "6"'
