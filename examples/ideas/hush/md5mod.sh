p 'sed -i -e "s/r/R/" test.conf'
p 'cat test.conf'
p 'if [ "# config signiture: $(head -n -1 test.conf | md5sum)" = \
        "$(tail -n 1 test.conf)" ]; then \
    echo "... UNchanged" ; \
  else \
    echo "*** changed" ; \
  fi'

