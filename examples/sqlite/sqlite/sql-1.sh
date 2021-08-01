#!/bin/sh
BASENAME=$(basename $0)
PROG=${BASENAME%%.sh}
DB=private.db
p "rm -f $DB # Initialize :-)"
p "cat $PROG.sql | sqlite3 -echo $DB"
p "ls -l $DB"
