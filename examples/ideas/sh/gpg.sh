p 'cat ./hello'
p 'gpg -ca ./hello'
p 'cat ./hello.asc'
p 'echo "#!/bin/sh">hello-secret'
p "echo 'cat - <<EOF | gpg -d --no-mdc-warning | while read x ;do eval \"\$x\"; done' >>hello-secret"
p 'cat ./hello.asc >>hello-secret'
p 'echo "EOF" >>hello-secret'
