p '/usr/bin/time -p ./prime7 "$(echo '2^16' | bc)">/dev/null'
p '/usr/bin/time -p ./prime7 "$(echo '2^20' | bc)">/dev/null'

