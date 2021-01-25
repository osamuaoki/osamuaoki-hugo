#!/bin/bash -e
# vim:set ai si sts=2 sw=2 et:

DATE=$(date -u --iso=sec)

echo -e "\033[0;32mList draft pages...\033[0m"
hugo list drafts

if git diff --exit-code >/dev/null ; then
  echo -e "\033[0;32mSource not changed from the last commit\033[0m"
else
  echo "\033[0;32mSource changed from the last commit\033[0m"
  git commit -a -m "source updated: $DATE"
fi

echo -e "\033[0;32mOutstanding draft pages...\033[0m"
hugo list drafts

echo -e "\033[0;32mBuilding HTML pages...\033[0m"
# Build the project after erasing old build excluding public/.git
rm -rf public/*
hugo # if using a theme, replace with `hugo -t <YOURTHEME>`

echo -e "\033[0;32mUploading HTML pages...\033[0m"
# Go To Public folder
cd public
# Add changes to git.
git add -A *
git commit -m "HTML rebuilt: $DATE"
git push origin master
# Come Back up to the Project Root
cd ..

# record submodule updates
git commit -a -m "submodule updated: $DATE"
git push origin master
