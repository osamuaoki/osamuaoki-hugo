#!/bin/sh
p 'cd deb/fridge-1.0; debuild -us -uc; cd -'
p 'ls -l deb'
p 'dpkg -c deb/fridge_1.0-1_all.deb'

