#!/bin/sh
p 'gcc -Wall `pkg-config --cflags --libs glib-2.0` -o upper upper.c'
