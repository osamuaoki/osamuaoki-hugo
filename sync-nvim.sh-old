#!/bin/bash -e
# vim:set ai si sts=2 sw=2 et:
# start with -f to force page rebuild

cd "$(dirname "$(which "$0")")"
BASE_DIR="$(pwd)"
echo "${0##*/}: base_dir=$BASE_DIR"
SOURCE_PACKAGES_DIR="$(pwd)/../packages"
echo "${0##*/}: source_packages_dir=$SOURCE_PACKAGES_DIR"
HTTP_REPO="$(pwd)/static/http"

cd "$SOURCE_PACKAGES_DIR"
echo "${0##*/}: cd to -> $(pwd)"

rm -rf "$HTTP_REPO"
mkdir -p "$HTTP_REPO"
for f in nvim*; do
  cp $f "$HTTP_REPO/"
done

cd "$BASE_DIR"
echo "${0##*/}: cd to -> $(pwd)"

