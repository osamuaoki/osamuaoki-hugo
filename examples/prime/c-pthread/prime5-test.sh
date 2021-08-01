p '/usr/bin/time -p ./prime5 "$(echo '2^20' | bc)">/dev/null'
p '/usr/bin/time -p ./prime5 "$(echo '2^24' | bc)">/dev/null'

