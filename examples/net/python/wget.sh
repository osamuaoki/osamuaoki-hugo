#!/bin/sh
echo '$ ./httpd 8080 &'
./httpd 8080 &
sleep 0.1
p "wget -O index2.html localhost:8080"
rm -f index2.html
killall httpd
