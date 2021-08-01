p 'perf record ./prime "$(echo '2^16' | bc)">/dev/null'
p 'perf report >perf.report'

