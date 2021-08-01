echo (gdb) list\n
list
echo (gdb) disas main\n
disas main
echo (gdb) disas/m main\n
disas/m main
echo (gdb) disas/r main\n
disas/r main
echo (gdb) # pos1\n
# pos1
echo (gdb) x/s 0x40067c\n
x/s 0x40067c
echo (gdb) x/14x 0x40067c\n
x/14x 0x40067c
echo (gdb) # pos2\n
# pos2
echo (gdb) start\n
start
echo (gdb) disas/m\n
disas/m
echo (gdb) # pos3\n
# pos3
echo (gdb) info reg edi\n
info reg edi
echo (gdb) nexti\n
nexti
echo (gdb) disas/m\n
disas/m
echo (gdb) info reg edi\n
info reg edi
echo (gdb) print /x $edi\n
print /x $edi
echo (gdb) x/s $edi\n
x/s $edi
echo (gdb) set $edi=$edi+1\n
set $edi=$edi+1
echo (gdb) x/s $edi\n
x/s $edi
echo (gdb) # pos4\n
# pos4
echo (gdb) step\n
step
echo (gdb) disas/m\n
disas/m
echo (gdb) # pos5\n
# pos5
echo (gdb) finish\n
finish
echo (gdb) disas/m\n
disas/m
echo (gdb) # pos6\n
# pos6
echo (gdb) cont\n
cont
echo (gdb) quit\n
quit
echo (gdb) # pos7\n
# pos7
