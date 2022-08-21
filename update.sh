#!/bin/bash -e
# vim:set ai si sts=2 sw=2 et:
# start with -f to force page rebuild

# can be started from sub-directory
cd "$(dirname "$(which "$0")")"

DATE=$(date -u --iso=sec)

echo -e "\033[0;32mOutstanding draft pages...\033[0m"
hugo list drafts

cd content
git add -A -- *
cd ..

cd static
git add -A -- *
cd ..

if git diff --cached --exit-code >/dev/null ; then
  echo -e "\033[0;31mSource not changed from the last commit\033[0m"
  if [ "$1" != "-f" ]; then
    exit
  fi
else
  echo -e "\033[0;32mSource changed from the last commit\033[0m"
  git commit -a -m "source updated: $DATE"
fi
git push origin main
echo -e "\033[0;34mFinished recording to source\033[0m"

##############################################################################
echo -e "\033[0;32mBuilding HTML pages...\033[0m"
# Build the project after erasing old build excluding public/.git
rm -rf public/*
hugo # if using a theme, replace with `hugo -t <YOURTHEME>`
##############################################################################
cd public
git add -A -- *
if git commit -m "HTML rebuilt: $DATE"; then
  echo -e "\033[0;34mSome thing to commit for HTML .... :-)\033[0m"
else
  echo -e "\033[0;31mNothing to commit for HTML .... :-(\033[0m"
  exit
fi
echo -e "\033[0;32mUploading HTML pages...\033[0m"
git push origin main
# Come Back up to the Project Root
cd ..
##############################################################################

# record submodule updates
if git diff --exit-code >/dev/null ; then
  echo -e "\033[0;31mSubmodule not changed from the last commit\033[0m"
  git commit -a -m "submodule not updated: $DATE"
  exit
else
  echo -e "\033[0;32mSubmodule changed from the last commit\033[0m"
  git commit -a -m "submodule updated: $DATE"
fi
git push origin main
echo -e "\033[0;34mFinished recording to submodule\033[0m"

