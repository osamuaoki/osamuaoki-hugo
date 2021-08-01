# compile
p "gcc -O9 -Wall -D'STYLE=0' -o prime0 prime-all.c"
p "gcc -O9 -Wall -D'STYLE=1' -o prime1 prime-all.c"
p "gcc -O9 -Wall -D'STYLE=2' -o prime2 prime-all.c"
p "gcc -O9 -Wall -D'STYLE=3' -o prime3 prime-all.c"
p "gcc -O9 -Wall -D'STYLE=4' -o prime4 prime-all.c"
# compile to asm
p "gcc -O9 -Wall -DSTYLE=0 -S -o prime0.s prime-all.c"
p "gcc -O9 -Wall -DSTYLE=1 -S -o prime1.s prime-all.c"
p "gcc -O9 -Wall -DSTYLE=2 -S -o prime2.s prime-all.c"
p "gcc -O9 -Wall -DSTYLE=3 -S -o prime3.s prime-all.c"
p "gcc -O9 -Wall -DSTYLE=4 -S -o prime4.s prime-all.c"
# bench mark
p '/usr/bin/time -p ./prime0 "$(echo '2^20' | bc)">/dev/null'
p '/usr/bin/time -p ./prime1 "$(echo '2^20' | bc)">/dev/null'
p '/usr/bin/time -p ./prime2 "$(echo '2^20' | bc)">/dev/null'
p '/usr/bin/time -p ./prime3 "$(echo '2^20' | bc)">/dev/null'
p '/usr/bin/time -p ./prime4 "$(echo '2^20' | bc)">/dev/null'
# bench mark (with more loops)
#p '/usr/bin/time -p ./prime0 "$(echo '2^24' | bc)">/dev/null'
#p '/usr/bin/time -p ./prime1 "$(echo '2^24' | bc)">/dev/null'
#p '/usr/bin/time -p ./prime2 "$(echo '2^24' | bc)">/dev/null'
#p '/usr/bin/time -p ./prime3 "$(echo '2^24' | bc)">/dev/null'
#p '/usr/bin/time -p ./prime4 "$(echo '2^24' | bc)">/dev/null'

