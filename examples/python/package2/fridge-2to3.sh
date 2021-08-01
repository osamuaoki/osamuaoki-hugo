#!/bin/sh
rm -f fridge/fridge.py*
cp ../package1/fridge/fridge.py fridge/fridge.py
p '2to3 -w fridge/fridge.py 2>/dev/null'
