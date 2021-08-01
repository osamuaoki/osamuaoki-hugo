p "gcc -g -Wall -lpthread -c prime.c"
p "gcc -g -Wall -lpthread -c checkprime.c"
p "gcc -g -Wall -lpthread -c subthread.c"
p "gcc -g -Wall -lpthread checkprime.o subthread.o prime.o -o prime-gdb"
p './prime-gdb "1090">/dev/null; echo $?'
p './prime-gdb "3"'
p './prime-gdb "4"'
p './prime-gdb "5"'
p './prime-gdb "6"'
