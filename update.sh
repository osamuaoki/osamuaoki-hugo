#!/bin/bash -e

echo -e "\033[0;32mDraft pages...\033[0m"

hugo list drafts

echo -e "\033[0;32mDeploying updates to GitHub...\033[0m"

# Remove files excluding .git
rm -rf public/*
# Build the project (after erasing old build).
hugo # if using a theme, replace with `hugo -t <YOURTHEME>`

# Go To Public folder
cd public
# Add changes to git.
git add -A *

# Commit changes.
msg="rebuilding site `date`"
if [ $# -eq 1 ]
  then msg="$1"
fi
git commit -m "$msg"

# Push source and build repos.
git push origin master

# Come Back up to the Project Root
cd ..

# record submodule updates
git commit -a -m "submodule: $msg"
git push origin master
