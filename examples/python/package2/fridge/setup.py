#!/usr/bin/python3
# vi:se ts=4 sts=4 et si:
from distutils.core import setup
setup(name='fridge',
    version='1.0',
    description='Python Distutils practice',
    author='Osamu Aoki',
    author_email='osamu@debian.org',
    url='http://people.debian.org/~osamu/',
    py_modules=['fridge'],
    scripts=['scripts/jane', 'scripts/joe', 'scripts/tom'],
    )
