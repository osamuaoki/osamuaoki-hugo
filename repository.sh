#!/bin/bash -e
# vim:set ai si sts=2 sw=2 et:
# start with -f to force page rebuild

# can be started from sub-directory in this source
cd "$(dirname "$(which "$0")")"
REPO_SOURCE_DIR="$(pwd)/../packages"
REPO_DEST="$(pwd)/static/debian"

cd "$REPO_SOURCE_DIR"
rm -f ./*.deb
rm -f ./*.changes
rm -f ./*.dsc
rm -f ./*.buildinfo
rm -f ./*.build
rm -f ./*.xz
#
if [ "$1" = "-c" ]; then
  exit 0
fi
rm -rf "$REPO_DEST/db"
rm -rf "$REPO_DEST/pool"
rm -rf "$REPO_DEST/dists"
#
for d in * ; do 
  if [ -d "$d" ]; then
    cd "$d"
    git zap
    debuild -us -uc
    cd ..
  fi
done
#
for f in *.changes; do
  debsign "$f"
  reprepro --ignore=wrongdistribution -b "$REPO_DEST" include sid "$f"
done
