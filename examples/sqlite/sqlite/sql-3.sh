#!/bin/sh
BASENAME=$(basename $0)
PROG=${BASENAME%%.sh}
DB=private.db
p "./$PROG.py"
