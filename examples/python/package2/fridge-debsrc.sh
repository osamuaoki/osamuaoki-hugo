#!/bin/sh
mkdir deb
p 'tar -xvzf fridge/dist/fridge-1.0.tar.gz -C deb'
p 'cd deb/fridge-1.0; dh_make -s --createorig --yes; cd -'
p 'ls -lR deb'
p ''
echo ''
echo '  ... update debian/control'
echo '  ... update debian/rules'
echo '  ... touch up template files'
echo '  ... remove unused template files'
echo ''
rm -rf deb/fridge-1.0/debian
cp -a debian deb/fridge-1.0
p 'ls -l deb/fridge-1.0/debian'
p 'cat deb/fridge-1.0/debian/control'
p 'cat deb/fridge-1.0/debian/rules'

