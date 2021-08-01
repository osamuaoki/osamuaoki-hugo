#!/usr/bin/python3
# -*- coding: utf-8 -*-
import sqlite3 as lite
import sys

con = lite.connect('private.db')
with con:
    c = con.cursor()        
    c.execute("""insert into phone values(
        'Abraham Lincoln', '+1-800-FREEDOM-1');""")
    c.execute("""select rowid,* from phone""")
    for row in c.fetchall():
        print ("%s : Name = %s, Phone =  %s" % (row[0], row[1], row[2]))
con.commit()
con.close()
