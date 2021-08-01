p '/usr/bin/time -p ./prime "$(echo '2^16' | bc)">/dev/null'
p '/usr/bin/time -p ./prime "$(echo '2^20' | bc)">/dev/null'
p '/usr/bin/time -p ./prime0 "$(echo '2^20' | bc)">/dev/null'

