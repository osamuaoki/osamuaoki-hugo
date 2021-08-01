p "valac -C hello-3.vala"
p "wc -l hello-3.vala ; wc -l hello-3.c"
p "cat hello-3.c|sed -e 's/\t/    /g'|fold # tab => 4 spaces"
