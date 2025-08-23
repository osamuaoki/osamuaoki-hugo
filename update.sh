#!/bin/bash -e
# vim:set ai si sts=2 sw=2 et:
# start with -f to force page rebuild
#
# can be started from sub-directory to update web page
cd "$(dirname "$(which "$0")")"
BASE_DIR="$(pwd)"
echo "osamuaoki-hugo: base_dir=$BASE_DIR"

DATE=$(date -u --iso=sec)

help() {
  echo "Syntax:"
  echo "  ${0##*/} [-l]"
  echo
  echo "Update hugo source and generated HTML"
  echo
  echo "If -l is specified, no remote repository updated"
  echo ""
  exit
}

# update remote repositories
if [ "$1" = "-l" ]; then
  REMOTE_UPDATE="false"
elif [ "$1" = "" ]; then
  REMOTE_UPDATE="true"
else
  help
  exit
fi

##############################################################################
# update local osamuaoki-hugo repository
##############################################################################
# stage any changes under data and image data
echo -e "\033[0;32mBuilding static data index ...\033[0m"
./index.sh http "File list for data files"
./index.sh img "File list for image files"
cd static
git add -A -- *
cd ..

# cheick content situation for hugo over drafts
echo -e "\033[0;32mOutstanding draft pages...\033[0m"
hugo list drafts

# stage any changes under content/
cd content
git add -A -- *
cd ..

# update local osamuaoki-hugo repository
if git diff --cached --exit-code >/dev/null ; then
  echo -e "\033[0;31mosamuaoki-hugo not changed from the last commit\033[0m"
else
  echo -e "\033[0;32mosamuaoki-hugo changed from the last commit\033[0m"
  git commit -a -m "source updated: $DATE"
fi

##############################################################################
# update remote osamuaoki-hugo repository
##############################################################################
if [ $REMOTE_UPDATE = "true" ]; then
  if git push -f origin main ; then
    echo -e "\033[0;34mFinished pushing to osamuaoki-hugo \033[0m"
  else
    echo -e "\033[0;34mFail to pushing to osamuaoki-hugo \033[0m"
  fi
else
  echo -e "\033[0;34mSkip pushing to osamuaoki-hugo \033[0m"
fi

##############################################################################
# update local osamuaoki.github.io repository
##############################################################################
echo "osamuaoki.github.io: base_dir=$BASE_DIR/public"
# update local git checkout by using hugo
echo -e "\033[0;32mBuilding HTML pages by hugo ...\033[0m"
# Erasing old build results.  NOTE: This excluds public/.git
rm -rf public/*
# build HTML files
hugo # if using a theme, replace with `hugo -t <YOURTHEME>`
# manually remove undesirable contents
cd public
rm -rf debian/db
rm -rf debian/conf

# stage any changes under public
# publishing to public HTML
git add -A -- *

if git diff --cached --exit-code >/dev/null ; then
  echo -e "\033[0;31mosamuaoki.github.io not changed from the last commit\033[0m"
else
  echo -e "\033[0;32mosamuaoki.github.io changed from the last commit\033[0m"
  git commit -a -m "HTML rebuild: $DATE"
fi

##############################################################################
# update remote osamuaoki.github.io repository
##############################################################################
if [ $REMOTE_UPDATE = "true" ]; then
  if git push -f origin main ; then
    echo -e "\033[0;34mFinished pushing to osamuaoki.github.io \033[0m"
  else
    echo -e "\033[0;34mFail to pushing to osamuaoki.github.io \033[0m"
  fi
else
  echo -e "\033[0;34mSkip pushing to osamuaoki.github.io \033[0m"
fi

cd ..

