p "valac -C hello-2.vala"
p "wc -l hello-2.vala ; wc -l hello-2.c"
p "cat hello-2.c|sed -e 's/\t/    /g'|fold # tab => 4 spaces"
