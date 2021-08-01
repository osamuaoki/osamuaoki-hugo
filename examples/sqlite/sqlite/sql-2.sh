#!/bin/sh
BASENAME=$(basename $0)
PROG=${BASENAME%%.sh}
DB=private.db
p "cat $PROG.sql"
p "cat $PROG.sql | sqlite3 -echo $DB"
