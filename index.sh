#!/bin/bash -e
# This is called from ./update.sh
DIR="$1"
TITLE="$2"

cd "$(dirname "$(which "$0")")"
BASE_DIR="$(pwd)"
echo "${0##*/}: base_dir=$BASE_DIR"
SOURCE_PACKAGES_DIR="$(pwd)/../packages"
echo "${0##*/}: source_packages_dir=$SOURCE_PACKAGES_DIR"

cd "static/$DIR"
echo "${0##*/}: cd to -> $(pwd)"

echo '<!DOCTYPE html>
<html lang="en-us">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Goofing Osamu | Static files</title>
  </head>

  <body>
    <nav>
    <ul class="menu">

      <li><a href="/">Home</a></li>

    </ul>
    <hr/>
    </nav>



<h1>Goofing Osamu</h1>
' > index.html


echo "
<p><strong>Goofing Osamu</strong> is a site where I keep random public memos.</p>
<h2 id=\"static-files\">$TITLE</h2>


<ul>

" >> index.html

for f in *; do
  if [ "$f" != "index.html" ]; then
    echo "
  <li>
    <a href=\"$f\">$f</a>
  </li>
" >> index.html
  fi
done

echo "
</ul>

  </body>
</html>
" >> index.html

