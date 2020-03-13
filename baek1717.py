# 2020-3-7
# solved
import sys
input = sys.stdin.readline
n, m = list(map(int, input().split()))
tree = [i for i in range(n+1)]

def find(i):
    p = tree[i]
    if p == i: return i
    else:
        r = find(p)
        tree[i] = r
        return r

def merge(a, b):
    r1 = find(a)
    r2 = find(b)
    tree[r2] = r1
    return r1


for _ in range(m):
    t, a, b = list(map(int, input().split()))
    if t:
        if find(a) == find(b):
            print("YES")
        else:
            print("NO")
    else:
        merge(a, b)
