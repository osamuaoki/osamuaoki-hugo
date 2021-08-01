#!/bin/sh
p 'ls -lR fridge'
p ''
p 'tar -tvzf fridge/dist/fridge-1.0.tar.gz'
p ''
p 'tar -xvzOf fridge/dist/fridge-1.0.tar.gz fridge-1.0/PKG-INFO'
