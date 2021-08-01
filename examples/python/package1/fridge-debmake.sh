#!/bin/sh
rm -rf fridge-1.0
p 'cd fridge; debmake -d -u 1.0 -b :python; cd -'
p 'ls -lR fridge-1.0'
p 'cat fridge-1.0/debian/control'
p 'cat fridge-1.0/debian/rules'

