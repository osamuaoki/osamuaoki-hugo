#!/bin/sh
p 'rm -rf dist'
p 'rm -r ~/.local/bin/jane ~/.local/bin/joe ~/.local/bin/tom'
p 'rm -r ~/.local/lib/python2.*/site-packages/fridge.py'
p 'rm -r ~/.local/lib/python2.*/site-packages/fridge-1.0.egg-info'
p 'rm -r ~/.local/lib/python2.*/site-packages/*.pyc'

