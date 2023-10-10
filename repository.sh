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

apt_update () {
  sudo aptitude update
  sudo aptitude install build-essential devscripts reprepro
  sudo apt-get build-dep unzip
}

remove_packages () {
  find . -maxdepth 1 \( -type f -o -type l \) -delete
}

# Native package
debian_native () {
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
    git rm --cached -r .
    git checkout "$BRANCH"
    git reset --hard HEAD
    git clean -d -f -x
    git pull --all
  fi
  debuild -us -uc -sa
}

# GBP-based non-native package
gbp_non_native () {
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
    git rm --cached -r .
    git checkout "$BRANCH"
    git reset --hard HEAD
    git clean -d -f -x
    git pull --all
  fi
  gbp export-orig
  debuild -us -uc -sa
}

# CMake-based non-Native package
cmake_native () {
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
}

#apt_update
cd "$SOURCE_PACKAGES_DIR"
remove_packages
cd "$SOURCE_PACKAGES_DIR"
echo "##############################################################"
echo "${0##*/}: pwd1 -> $(pwd)"
echo "##############################################################"
debian_native "git@github.com:osamuaoki/bss.git" main
cd "$SOURCE_PACKAGES_DIR"
echo "##############################################################"
echo "${0##*/}: pwd2 -> $(pwd)"
echo "##############################################################"
debian_native "git@github.com:osamuaoki/osamu-task.git" main
cd "$SOURCE_PACKAGES_DIR"
echo "##############################################################"
echo "${0##*/}: pwd3 -> $(pwd)"
echo "##############################################################"
gbp_non_native "git@github.com:osamuaoki/unzip.git" master
cd "$SOURCE_PACKAGES_DIR"
echo "##############################################################"
echo "${0##*/}: pwd4 -> $(pwd)"
echo "##############################################################"
cmake_native "https://github.com/neovim/neovim.git" release-0.9

cd "$BASE_DIR"
echo "${0##*/}: cd to -> $(pwd)"

if [ "$1" = "-c" ]; then
  exit 0
fi

./sync.sh

