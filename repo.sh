#!/bin/bash -e
# vim:set ai si sts=2 sw=2 et:
# start with -f to force page rebuild

# can be started from sub-directory in this source
cd "$(dirname "$(which "$0")")"
BASE_DIR="$(pwd)"
echo "${0##*/}: base_dir=$BASE_DIR"
SOURCE_PACKAGES_DIR="$(pwd)/../packages"
echo "${0##*/}: source_packages_dir=$SOURCE_PACKAGES_DIR"

DEB_REPO="$(pwd)/static/debian"
HTTP_REPO="$(pwd)/static/http"
VERBOSE=""
#VERBOSE="--verbose"
BUILD_VERSION="0.0~$(date -u +%y%m%d.%H%M%S)"

help() {
  echo "Syntax:"
  echo "  ${0##*/} name1 name2 ..."
  echo
  echo "Names: nvim bss unzip osamu-task incus-ui-canonical"
  exit
}

apt_update() {
  sudo aptitude update
  sudo aptitude install build-essential devscripts reprepro
  sudo apt-get build-dep unzip
}

# Native package
debian_native() {
  cd "$SOURCE_PACKAGES_DIR"
  REPO_URL="$1"
  BRANCH="$2"
  REPO_DIR="${REPO_URL##*/}"
  REPO_DIR="${REPO_DIR%.git}"
  if [ ! -d "$REPO_DIR" ]; then
    git clone "$REPO_URL"
    cd "$REPO_DIR"
    git checkout "$BRANCH"
  else
    cd "$REPO_DIR"
    #git stash
    git rm --cached -r .
    git checkout "$BRANCH"
    git reset --hard HEAD
    git clean -d -f -x
    git pull --all
  fi
  debuild -us -uc -sa
  cd "$SOURCE_PACKAGES_DIR"
}

# GBP-based non-native package
gbp_non_native() {
  cd "$SOURCE_PACKAGES_DIR"
  REPO_URL="$1"
  BRANCH="$2"
  REPO_DIR="${REPO_URL##*/}"
  REPO_DIR="${REPO_DIR%.git}"
  if [ ! -d "$REPO_DIR" ]; then
    git clone "$REPO_URL"
    cd "$REPO_DIR"
    git checkout "$BRANCH"
  else
    cd "$REPO_DIR"
    #git stash
    git rm --cached -r .
    git checkout "$BRANCH"
    git reset --hard HEAD
    git clean -d -f -x
    git pull --all
  fi
  gbp export-orig
  debuild -us -uc -sa
  cd "$SOURCE_PACKAGES_DIR"
}

# CMake-based non-Native package
cmake_native() {
  cd "$SOURCE_PACKAGES_DIR"
  REPO_URL="$1"
  BRANCH="$2"
  REPO_DIR="${REPO_URL##*/}"
  REPO_DIR="${REPO_DIR%.git}"
  BUILD_TYPE="RelWithDebInfo"
  DEB_ORIG="nvim-linux64.deb"
  DEB_NAME="nvim"
  DEB_ARCH="amd64"
  DEB_BUILD="${DEB_NAME}_${BUILD_VERSION}_${DEB_ARCH}.deb"
  if [ ! -d "$REPO_DIR" ]; then
    git clone "$REPO_URL"
    cd "$REPO_DIR"
    git checkout "$BRANCH"
  else
    cd "$REPO_DIR"
    #git stash
    git rm --cached -r .
    git checkout "$BRANCH"
    git reset --hard HEAD
    git clean -d -f -x
    git pull --all
  fi
  git submodule update --init --recursive

  cmake -S cmake.deps -B .deps -G Ninja -D CMAKE_BUILD_TYPE=${BUILD_TYPE}
  cmake --build .deps
  cmake -B build -G Ninja -D CMAKE_BUILD_TYPE=$BUILD_TYPE
  mkdir debian
  echo "${DEB_NAME} (${BUILD_VERSION}) unstable; urgency=medium

  * Fake changelog with bogus date.

 -- Osamu Aoki <osamu@debian.org>  Mon, 09 Oct 2023 23:38:14 +0900" > debian/changelog
  echo "Source: ${DEB_NAME}
Section: editor
Priority: optional
Maintainer: Osamu Aoki <osamu@debian.org>
Build-Depends: debhelper-compat (= 13)
Standards-Version: 4.6.2
Homepage: ${REPO_URL}

Package: ${DEB_NAME}
Architecture: any
Multi-Arch: same
Description: Locally build nvim (branch=$BRANCH)
 This is not really ready for official archive.  Very hackish." > debian/control
  echo "${DEB_NAME}_${BUILD_VERSION}_${DEB_ARCH}.deb editor optional" > debian/files
  tar --xz --exclude-vcs -c -v -f ../${DEB_NAME}-${BUILD_VERSION}.tar.xz ./
  cmake --build build
  cd build
  cpack -G DEB $VERBOSE
  cp $DEB_ORIG ../../$DEB_BUILD
  cd "$SOURCE_PACKAGES_DIR"
}

remove_package() {
  # $1 package name
  cd "$SOURCE_PACKAGES_DIR"
  find . -maxdepth 1 \( -type f -o -type l \) -name "$1*" -delete
}

nvim2http() {
  rm -rf "$HTTP_REPO"
  mkdir -p "$HTTP_REPO"
  cd "$SOURCE_PACKAGES_DIR"
  for f in nvim*; do
    cp $f "$HTTP_REPO/"
  done
}

debrepo() {
  debsign $1
  reprepro --ignore=wrongdistribution -b "$DEB_REPO" include sid $1
}

cd "$SOURCE_PACKAGES_DIR"
apt_update

while [ -n "$1" ]; do
  case "$1" in
    N*)
      remove_package nvim
      cmake_native "https://github.com/neovim/neovim.git" main
      #nvim2http
      ;;
    n*)
      remove_package nvim
      cmake_native "https://github.com/neovim/neovim.git" release-0.10
      nvim2http
      ;;
    o*)
      remove_package osamu-task
      debian_native "git@github.com:osamuaoki/osamu-task.git" main
      debrepo osamu-task*.changes

      ;;
    b*)
      remove_package bss
      debian_native "git@github.com:osamuaoki/bss.git" main
      debrepo bss*.changes
      ;;
    i*)
      remove_package incus-ui-canonical
      gbp_non_native "git@github.com:osamuaoki/incus-ui-canonical.git" debian
      debrepo incus-ui-canonical*.changes
      ;;
    u*)
      remove_package unzip
      gbp_non_native "git@github.com:osamuaoki/unzip.git" master
      debrepo unzip*.changes
      ;;
    *)
      help
      ;;
  esac
  shift
done
