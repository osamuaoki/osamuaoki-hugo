set trace-commands on
file prime-gdb
set arg 1090
break prime.c:44 if i >= 61
# define macro pre-definition
define xprint
print i
print tail
printf "thd[i].head=%08X\n", thd[i].head
printf "thd[i-1].head=%08X\n", thd[i-1].head
printf "thd[i-2].head=%08X\n", thd[i-2].head
end
# autorun xprint
command 1
xprint
end
# debug run start
run
cont
cont
cont
quit
