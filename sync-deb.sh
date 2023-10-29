#!/bin/bash -e
# vim:set ai si sts=2 sw=2 et:
# start with -f to force page rebuild

cd "$(dirname "$(which "$0")")"
BASE_DIR="$(pwd)"
echo "${0##*/}: base_dir=$BASE_DIR"
SOURCE_PACKAGES_DIR="$(pwd)/../packages"
echo "${0##*/}: source_packages_dir=$SOURCE_PACKAGES_DIR"
DEB_REPO="$(pwd)/static/debian"

cd "$SOURCE_PACKAGES_DIR"
echo "${0##*/}: cd to -> $(pwd)"

mkdir -p "$DEB_REPO"
rm -rf "$DEB_REPO/db"
rm -rf "$DEB_REPO/dists"
rm -rf "$DEB_REPO/pool"
for f in *.changes; do
  debsign "$f"
  reprepro --ignore=wrongdistribution -b "$DEB_REPO" include sid "$f"
done

cd "$BASE_DIR"
echo "${0##*/}: cd to -> $(pwd)"

