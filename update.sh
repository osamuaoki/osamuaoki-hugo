#!/bin/bash -e
# vim:set ai si sts=2 sw=2 et:
# start with -f to force page rebuild

DATE=$(date -u --iso=sec)

echo -e "\033[0;32mOutstanding draft pages...\033[0m"
hugo list drafts

if git diff --exit-code >/dev/null ; then
  echo -e "\033[0;31mSource not changed from the last commit\033[0m"
  if [ "$1" != "-f" ]; then
    exit
  fi
else
  echo -e "\033[0;32mSource changed from the last commit\033[0m"
  git commit -a -m "source updated: $DATE"
fi

##############################################################################
echo -e "\033[0;32mBuilding HTML pages...\033[0m"
# Build the project after erasing old build excluding public/.git
rm -rf public/*
hugo # if using a theme, replace with `hugo -t <YOURTHEME>`

echo -e "\033[0;32mUploading HTML pages...\033[0m"
# Go To Public folder
cd public
# Add changes to git.
git add -A *
if git commit -m "HTML rebuilt: $DATE"; then
  echo -e "\033[0;31mNothing to commit .... Finished\033[0m"
  exit
fi
git push origin master
# Come Back up to the Project Root
cd ..
##############################################################################

# record submodule updates
if git diff --exit-code >/dev/null ; then
  echo -e "\033[0;31mSubmodule not changed from the last commit\033[0m"
else
  echo -e "\033[0;32mSubmodule changed from the last commit\033[0m"
  git commit -a -m "submodule updated: $DATE"
fi
git push origin master
echo -e "\033[0;34mFinished\033[0m"

