p "gcc -Wall -o popen popen.c"
echo '$ echo PID=$$'
echo PID=$$
echo '$ echo PPID=$PPID'
echo PPID=$PPID
echo "\$ ./popen"
./popen
echo "\$ ./popen 2>/dev/null"
./popen 2>/dev/null
echo "\$ ./popen >/dev/null"
./popen >/dev/null
