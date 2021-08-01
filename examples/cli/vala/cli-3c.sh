PROG=cli-3
p "valac -C ${PROG}.vala"
p "wc -l ${PROG}.vala ; wc -l ${PROG}.c"
p "cat ${PROG}.c |sed -e 's/\t/    /g'|fold  # tab => 4 spaces"
