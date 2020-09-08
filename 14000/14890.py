# 2020.3.14
# solved

import sys
input = sys.stdin.readline

def possible(r):
    lastHedge = -1
    for i in range(n-1):
        if r[i] == r[i+1]:
            continue
        elif abs(r[i] - r[i+1]) != 1:
            return False
        else:
            if r[i] > r[i+1]:
                #check out of range
                if i+l > n-1:
                    return False
                for d in range(l-1):
                    if r[i+1] != r[i+d+2]:
                        return False
                lastHedge = i+l
            else:
                #check out of range
                if i-l+1 < 0 or i-l+1 <= lastHedge:
                    return False
                for d in range(l-1):
                    if r[i] != r[i-d-1]:
                        return False
    return True

n, l = list(map(int, input().split()))
roads = []
for _ in range(n):
    roads.append(list(map(int, input().split())))

for i in range(n):
    col = []
    for j in range(n):
        col.append(roads[j][i])
    roads.append(col)

res = 0
for road in roads:
    if possible(road):
        res += 1

print(res)