#!/bin/bash -e
# vim:set ai si sts=2 sw=2 et:
# start with -f to force page rebuild

# can be started from sub-directory in this source
cd "$(dirname "$(which "$0")")"
REPO_SOURCE_DIR="$(pwd)/../packages"
REPO_DEST="$(pwd)/static/debian"

mkdir -p $REPO_DEST
cd "$REPO_SOURCE_DIR"
for f in *.changes; do
  reprepro --ignore=wrongdistribution -b "$REPO_DEST" include sid "$f"
done
