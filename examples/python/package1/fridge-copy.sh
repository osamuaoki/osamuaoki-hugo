#!/bin/sh
mkdir dist
p 'tar -xvzf fridge/dist/fridge-1.0.tar.gz -C dist'
p 'cd dist/fridge-1.0; python setup.py install --user;cd -'
p 'jane|fold'
