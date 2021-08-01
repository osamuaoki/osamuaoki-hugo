set trace-commands on
# start program with argument 1090 and stop at the first line
start 1090
# break at the start of  subthread.c
break subthread.c:1
# define macro pre-definition
define xprint
printf "thd->n0=%08X\n", thd->n0
printf "thd->n1=%08X\n", thd->n1
bt
end
# autorun xprint at breakpoint 2
command 2
xprint
end
# conditional breakpoint
break prime.c:44 if i >= 3
# one time break point
tbreak 16
c
print tmax
set tmax = 4
print tmax
bt full
s
bt f
finish
where f
c
c
c
c
info thread
thread apply all bt
c
print i
c
quit
