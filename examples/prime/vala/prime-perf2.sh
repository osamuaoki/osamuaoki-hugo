p 'perf record ./prime "$(echo '2^20' | bc)">/dev/null'
p 'perf report >perf.report'

