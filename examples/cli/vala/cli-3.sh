PROG=cli-3
p "valac -v ${PROG}.vala"
p "./${PROG} -avf BOGUS.txt --long --longextra=FOO X1 X2"
p "./${PROG} -b"
p "./${PROG} --help"
