def solve(l, cur = 0):
    if len(l) != 0:
        if l[0][0] <= len(l):
            cur = max(solve(l[l[0][0]:], cur+l[0][1]), solve(l[1:], cur))
    return cur

N = int(input())
l = []
for _ in range(N):
    T, P = map(int, input().split())
    l.append((T, P))
print(solve(l))
