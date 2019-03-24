# source to build "Goofing Osamu"

## Source code of "Goofing Osamu" web page

[Goofing Osamu](https://osamuaoki.github.io) is built by using this source code
and `hugo`.  This source code uses xmin-hugo theme as template theme.

  * [hugo](https://gohugo.io/)
  * [xmin-hugo](https://github.com/yihui/hugo-xmin)

`xmin-hugo` is used via `git submodule`.

You can check out all submodules as:

```
 $ git clone git@github.com:osamuaoki/osamuaoki-hugo.git
 $ git submodule update --init
```

Here:

  * https://osamuaoki.github.io (URL to access webpages)
  * https://github.com/osamuaoki/osamuaoki.github.io (raw HTML files)

## Adding a post

For example, let's add a page in jp with:

```
 $ ls -l content/jp
total 16
-rw-rw-r-- 1 osamu osamu  175 Feb  9 17:14 _index.md
-rw-rw-r-- 1 osamu osamu 3021 Mar 23 19:05 note-00001.md
-rw-rw-r-- 1 osamu osamu 1602 Mar 23 19:05 note-00002.md
-rw-rw-r-- 1 osamu osamu 4018 Mar 23 21:13 note-00003.md
 $ hugo new jp/note-00004.md
```

Copy header part from old pages to make them consistent.


