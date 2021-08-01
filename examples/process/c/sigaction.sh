p "gcc -Wall -o sigaction sigaction.c"
echo '$ ./sigaction &' 
./sigaction &
echo '$  jobs'
jobs
p "ps -l" |grep -v -e 'p$' -e 'sed$'
p "killall -v -s INT sigaction"
echo '$  jobs'
jobs
p "ps -l" |grep -v -e 'p$' -e 'sed$'
p "killall -v -s INT sigaction"
echo '$  jobs'
jobs
p "ps -l" |grep -v -e 'p$' -e 'sed$'
echo '$ ./sigaction &' 
./sigaction &
echo '$  jobs'
jobs
echo '$ ./sigaction &' 
p "ps -l" |grep -v -e 'p$' -e 'sed$'
p "killall -v -s HUP sigaction"
echo '$  jobs'
jobs
echo '$ ./sigaction &' 
p "ps -l" |grep -v -e 'p$' -e 'sed$'
p "killall -v -s KILL sigaction"
echo '$  jobs'
jobs
p "ps -l" |grep -v -e 'p$' -e 'sed$'
