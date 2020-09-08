def parse():
    return list(map(int, input().split()))

n, = parse()
m, = parse()

friends = [[] for _ in range(n+1)]
for _ in range(m):
    a, b = parse()
    friends[a].append(b)
    friends[b].append(a)

ret = 0
invited = [0] * (n+1)
invited[1] = 1

for i in friends[1]:
    if invited[i] == 0:
        invited[i] = 1
        ret += 1
    for j in friends[i]:
        if invited[j] == 0:
            invited[j] = 1
            ret += 1
print(ret)
