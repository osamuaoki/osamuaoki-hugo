echo '$ ./sigtrap &'
./sigtrap &
echo '$ ps'
ps
echo '$ jobs'
jobs
p 'killall -s HUP sigtrap'
sleep 0.1
p 'killall -s TSTP sigtrap'
sleep 0.1
p 'killall -s 1 sigtrap'
sleep 0.1
p 'killall -HUP sigtrap'
echo '$ ps'
ps
echo '$ jobs'
jobs
echo '$ killall -s TERM sigtrap'
killall -s TERM sigtrap
echo '$ ps'
ps
echo '$ jobs'
jobs
echo '$ killall -s KILL sigtrap'
killall -s KILL sigtrap
echo '$ ps'
ps
echo '$ jobs'
jobs
