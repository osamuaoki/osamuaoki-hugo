p "g++ -Wall -lboost_program_options -o cli cli.cxx"
p "./cli -avf BOGUS.txt --long --longextra=FOO X1 X2"
p "./cli -b"
p "./cli --help"

