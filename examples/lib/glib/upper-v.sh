#!/bin/sh
p 'gcc -v -Wall `pkg-config --cflags --libs glib-2.0` -o upper-v upper.c'
