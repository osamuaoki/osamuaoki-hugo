#!/bin/bash -e
# vim:set ai si sts=2 sw=2 et:
# start with -f to force page rebuild

# can be started from sub-directory
cd "$(dirname "$(which "$0")")"

rm -rf static/debian/db
rm -rf static/debian/pool
rm -rf static/debian/dists

BASEDIR="$(pwd)/static/debian"

for f in ../packages/*.changes; do
  reprepro --ignore=wrongdistribution -b "$BASEDIR" include sid "$f"
done
