p "gcc -Wall -o signal signal.c"
echo '$ ./signal &' 
./signal &
echo '$  jobs'
jobs
p "ps -l" |grep -v -e 'p$' -e 'sed$'
p "killall -v -s INT signal"
echo '$  jobs'
jobs
p "ps -l" |grep -v -e 'p$' -e 'sed$'
p "killall -v -s INT signal"
echo '$  jobs'
jobs
p "ps -l" |grep -v -e 'p$' -e 'sed$'
echo '$ ./signal &' 
./signal &
echo '$  jobs'
jobs
echo '$ ./signal &' 
p "ps -l" |grep -v -e 'p$' -e 'sed$'
p "killall -v -s HUP signal"
echo '$  jobs'
jobs
echo '$ ./signal &' 
p "ps -l" |grep -v -e 'p$' -e 'sed$'
p "killall -v -s KILL signal"
echo '$  jobs'
jobs
p "ps -l" |grep -v -e 'p$' -e 'sed$'
