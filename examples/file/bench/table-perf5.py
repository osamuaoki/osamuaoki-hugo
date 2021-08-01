#!/usr/bin/python
# vi:ts=4:sts=4:et
#123456789012345678
#       5735.036623 task-clock                #    0.999 CPUs utilized
#               488 context-switches          #    0.085 K/sec
#                 6 cpu-migrations            #    0.001 K/sec
#             2,806 page-faults               #    0.489 K/sec
#    17,291,280,697 cycles                    #    3.015 GHz                     [...
#     3,022,579,360 stalled-cycles-frontend   #   17.48% frontend cycles idle    [...
#     1,368,341,807 stalled-cycles-backend    #    7.91% backend  cycles idle    [...
#    39,633,755,305 instructions              #    2.29  insns per cycle
#                                             #    0.08  stalled cycles per insn [...
#     8,208,558,092 branches                  # 1431.300 M/sec                   [...
#        64,323,034 branch-misses             #    0.78% of all branches         [...
#
#       5.740777576 seconds time elapsed
import sys, os, re
def tableline(item):
    print "|" + item + "|" + perf[0][item] + "|" +  perf[1][item]  + "|" + perf[2][item] + "|" +  perf[3][item] + "|" +  perf[4][item]


perf = []
for j in range(0,5):
    data = {}
    for i in range(0,11):
        line = sys.stdin.readline()
        data[line[19:50].strip()] = line[:19].strip()
    perf.append(data)

print "|Performance counter stats|char|block|block big|mmap memcpy|mmap write"
tableline("seconds time elapsed")
tableline("task-clock")
tableline("context-switches")
tableline("cpu-migrations")
tableline("page-faults")
tableline("cycles")
tableline("stalled-cycles-frontend")
tableline("stalled-cycles-backend")
tableline("branches")
tableline("branch-misses")


