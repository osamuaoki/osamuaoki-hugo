#!/bin/bash -e
# vim:set ai si sts=2 sw=2 et:
# start with -f to force page rebuild


# Directory name for repository found in the parent directory
REPODIR0="packages"

# can be started from sub-directory in this source
cd "$(dirname "$(which "$0")")"
BASEDIR="$(pwd)/static/debian"
REPODIR="$(pwd)/../$REPODIR0"

cd "$REPODIR"

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
rm -rf "$BASEDIR/static/debian/db"
rm -rf "$BASEDIR/static/debian/pool"
rm -rf "$BASEDIR/static/debian/dists"
#
for d in * ; do 
  if [ -d "$d" ]; then
    cd "$d"
    git zap
    debuild # -us -uc
    cd ..
  fi
done
#
for f in *.changes; do
  debsign "$f"
  reprepro --ignore=wrongdistribution -b "$BASEDIR" include sid "$f"
done
