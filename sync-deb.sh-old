#!/bin/bash -e
# vim:set ai si sts=2 sw=2 et:
# start with -f to force page rebuild

cd "$(dirname "$(which "$0")")"
BASE_DIR="$(pwd)"
echo "${0##*/}: base_dir=$BASE_DIR"
SOURCE_PACKAGES_DIR="$(pwd)/../packages"
echo "${0##*/}: source_packages_dir=$SOURCE_PACKAGES_DIR"
DEB_REPO="$(pwd)/static/debian"

debrepo () {
  debsign "$1"
  reprepro --ignore=wrongdistribution -b "$DEB_REPO" include sid "$1"
}


mkdir -p "$DEB_REPO"
rm -rf "$DEB_REPO/db"
rm -rf "$DEB_REPO/dists"
rm -rf "$DEB_REPO/pool"

cd "$SOURCE_PACKAGES_DIR"
case $1 in
  a*) # all
    for f in *.changes; do
      debrepo "$f"
    done
    ;;
  b*) # bss
    debrepo bss*.changes
    ;;
  o*) # osamu-task
    debrepo osamu*.changes
    ;;
  i*) # incus-ui-canonical
    debrepo incus-ui-canonical*.changes
    ;;
  u*) # unzip
    debrepo unzip*.changes
    ;;
esac

