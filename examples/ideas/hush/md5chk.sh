p 'if [ "# config signiture: $(head -n -1 test.conf | md5sum)" = \
        "$(tail -n 1 test.conf)" ]; then \
    echo "... UNchanged" ; \
  else \
    echo "*** changed" ; \
  fi'

