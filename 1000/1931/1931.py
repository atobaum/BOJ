import sys

N = int(input())
meetings = []
for _ in range(N):
    s, e = map(int, sys.stdin.readline().split())
    meetings.append((e, s))

meetings.sort()
ret = 0
t = 0
for e, s in meetings:
    if s < t:
        continue
    else:
        t = e
        ret += 1
print(ret)
