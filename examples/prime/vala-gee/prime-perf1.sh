p 'perf stat ./prime "$(echo '2^20' | bc)">/dev/null' 2>&1 |col -xb

