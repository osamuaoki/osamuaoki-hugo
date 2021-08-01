#!/bin/sh
p "./httpd6 8080 ../01_static"
sleep 0.1
p "wget localhost:8080"
rm -f index.html
killall httpd6
