def parse():
    return list(map(int, input().strip()))
def solve(x, y, m):
    if m == 1:
        return str(data[y][x])
    nextM = int(m/2)
    ret = solve(x, y, nextM) + solve(x+nextM, y, nextM) + solve(x, y+nextM, nextM) + solve(x+nextM, y+nextM, nextM)
    for x in ret:
        if not (x.isdigit() and (x == ret[0])):
            return '('+ret+')'
    return ret[0]

n = int(input())
data = []
for _ in range(n):
    temp = [char for char in input()]
    data.append(temp)

print(solve(0, 0, n))
