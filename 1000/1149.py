# 2020.3.27
# pypy3에서는 되는데 python3에서는 안됨..
def parse():
    return list(map(int, input().split()))

n, = parse()
cost = []
for _ in range(n):
    cost.append(parse())

# memo[i][j]: i번집이 j색으로 칠했을 때 i번째 집 이후의 집들 칠한 최소 비용
memo = [[None]*3 for _ in range(n)]
def solve(i, j):
    if i == n-1:
        return cost[i][j]

    if memo[i][j] is not None:
        return memo[i][j]

    ret = []
    for c in [0,1,2]:
        if c == j:
            continue
        ret.append(solve(i+1, c)+cost[i][j])
    ret = min(ret)
    memo[i][j] = ret
    return ret

ret = min(solve(0, 0), solve(0, 1), solve(0,2))
print(ret)
