#!/bin/bash -e
# vim:set ai si sts=2 sw=2 et:
# start with -f to force page rebuild

# can be started from sub-directory in this source to update
# Personal DEB package repository before ./update.sh
#
# When reorganizing published debian repository, remove files in static/debian except for static/debian/conf.
#
# When reorganizing published http directory, change files in static/http
#
cd "$(dirname "$(which "$0")")"
BASE_DIR="$(pwd)"
echo "${0##*/}: base_dir=$BASE_DIR"
# all packages in this private deb repo has cloned source tree
# at ../packages/<projectname>
SOURCE_PACKAGES_DIR="$(pwd)/../packages"
echo "${0##*/}: source_packages_dir=$SOURCE_PACKAGES_DIR"

DEB_REPO="$(pwd)/static/debian"
HTTP_REPO="$(pwd)/static/http"
VERBOSE=""

LOCAL_BUILD=true
REMOTE_UPDATE=true

#VERBOSE="--verbose"
BUILD_VERSION="0.0~$(date -u +%y%m%d.%H%M%S)"

help() {
  echo "Syntax:"
  echo "  ${0##*/} [-l|-r] name ..."
  echo
  echo "Build deb packages to http data site (release-0.11):"
  echo "  name: nvim"
  echo "Build deb packages to debian repository:"
  echo "  name: bss unzip osamu-task"
  echo "Reset debian repository"
  echo "  name: reset"
  echo ""
  echo "  -l: Local build only (No remote update)"
  echo "  -r: Remote update only (No local build)"
  echo ""
  echo ""
  exit
}

apt_update() {
  sudo aptitude update || true
  sudo aptitude install build-essential devscripts reprepro
  sudo apt-get build-dep unzip
}

# Update and build Native package
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

# Update and build GBP-based non-native package
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

# Update and build CMake-based non-Native package
cmake_native() {
  cd "$SOURCE_PACKAGES_DIR"
  REPO_URL="$1"
  BRANCH="$2"
  REPO_DIR="${REPO_URL##*/}"
  REPO_DIR="${REPO_DIR%.git}"
  BUILD_TYPE="RelWithDebInfo"
  DEB_ORIG="nvim-linux-x86_64.deb"
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

# Remove old build result for package $1
remove_build_result() {
  # $1 package name
  cd "$SOURCE_PACKAGES_DIR"
  find . -maxdepth 1 \( -type f -o -type l \) -name "$1*" -delete
}

# remove old nvim packages and copy new source and binary packages for nvim to
# static http site
nvim2http() {
  mkdir -p "$HTTP_REPO"
  cd "$HTTP_REPO"
  rm -rf nvim*
  cd "$SOURCE_PACKAGES_DIR"
  for f in nvim*; do
    cp $f "$HTTP_REPO/"
  done
}

# copy source and binary packages for $1 to private APT site
debrepo() {
  echo "I: pwd=$(pwd) arg=$1 dest=$DEB_REPO"
  debsign $1
  reprepro --ignore=wrongdistribution -b "$DEB_REPO" include sid $1
}

# debrepo_rm() {
#   debsign $1
#   reprepro --ignore=wrongdistribution -b "$DEB_REPO" remove sid $1
# }

debrepo_reset() {
   rm -rf $DEB_REPO/db
   rm -rf $DEB_REPO/dists
   rm -rf $DEB_REPO/pool
}

cd "$SOURCE_PACKAGES_DIR"
apt_update

while [ -n "$1" ]; do
  case "$1" in
    -l) # local build only
      LOCAL_BUILD=true
      REMOTE_UPDATE=false
      ;;
    -r) # remote update only
      LOCAL_BUILD=false
      REMOTE_UPDATE=true
      ;;
    n*)
      if $LOCAL_BUILD ; then
        remove_build_result nvim
        cmake_native "https://github.com/neovim/neovim.git" release-0.11
      fi
      if $REMOTE_UPDATE ; then
        nvim2http
      fi
      ;;
    o*)
      if $LOCAL_BUILD ; then
        remove_build_result osamu-task
        debian_native "git@github.com:osamuaoki/osamu-task.git" main
      fi
      if $REMOTE_UPDATE ; then
        debrepo osamu-task*.changes
      fi
      ;;
    b*)
      if $LOCAL_BUILD ; then
        remove_build_result bss
        debian_native "git@github.com:osamuaoki/bss.git" main
      fi
      if $REMOTE_UPDATE ; then
        debrepo bss*.changes
      fi
      ;;
    u*)
      if $LOCAL_BUILD ; then
        remove_build_result unzip
        gbp_non_native "git@github.com:osamuaoki/unzip-i18n.git" debian/latest
      fi
      if $REMOTE_UPDATE ; then
        debrepo unzip*.changes
      fi
      ;;
    reset)
      debrepo_reset
      ;;
    *)
      help
      ;;
  esac
  shift
done
