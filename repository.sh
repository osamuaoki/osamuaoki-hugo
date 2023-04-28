#!/bin/bash -e
# vim:set ai si sts=2 sw=2 et:
# start with -f to force page rebuild

# can be started from sub-directory in this source
cd "$(dirname "$(which "$0")")"
REPO_SOURCE_DIR="$(pwd)/../packages"
REPO_DEST="$(pwd)/static/debian"

rm -rf "$REPO_SOURCE_DIR"
mkdir -p "$REPO_SOURCE_DIR"
cd "$REPO_SOURCE_DIR"
# Native package
git clone git@github.com:osamuaoki/osamu-task.git
cd osamu-task
git checkout main
cd ..
# Native package
git clone git@github.com:osamuaoki/bss.git
cd bss
git checkout main
cd ..
# Non-Native package
git clone git@github.com:osamuaoki/unzip.git
cd unzip
git checkout upstream
git checkout pristine-tar
git checkout master
gbp export-orig
cd ..
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
    #git zap
    debuild -us -uc -sa
    cd ..
  fi
done
#
for f in *.changes; do
  debsign "$f"
  reprepro --ignore=wrongdistribution -b "$REPO_DEST" include sid "$f"
done
