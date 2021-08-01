#!/bin/sh
p 'dpkg -L libc6:amd64|grep ^/lib/x86_64-linux-gnu/.*\.so$'
