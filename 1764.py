s = set([])
n, m = map(int, input().split())

l = []

for _ in range(n):
    s.add(input())
for _ in range(m):
    i = input()
    if i in s:
        l.append(i)
l.sort()

print(len(l))
for s in l:
    print(s)
