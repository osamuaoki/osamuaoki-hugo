p "gcc -Wall -o cli-log cli-log.c"
p "./cli-log Hello"
p "./cli-log Hello World"
p "./cli-log -v Hello World"
p "./cli-log -vv Hello World"
p "./cli-log -vvv Hello World"
p "./cli-log -vvv Hello World EXT"
p "DEBUG=2 ./cli-log -v Hello World"

