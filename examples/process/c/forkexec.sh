p "gcc -Wall -o forkexec forkexec.c"
echo "\$ ./forkexec"
./forkexec
echo "$"
echo "\$ ./forkexec 2>/dev/null"
./forkexec 2>/dev/null
echo "$"
echo "\$ ./forkexec >/dev/null"
./forkexec >/dev/null

