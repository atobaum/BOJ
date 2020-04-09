import sys
sys.setrecursionlimit(10**6)
def parse():
    return list(map(int, sys.stdin.readline().split()))

memo = None
# finish를 짓는 데 걸리는 최소 총 시간
def solve(adj, time, finish):
    if memo[finish] is not None:
        return memo[finish]

    if len(adj[finish]) == 0:
        memo[finish] = time[finish]
    else:
        ret = max([solve(adj, time, req) for req in adj[finish]]) + time[finish]
        memo[finish] = ret
    return memo[finish]

T, = parse()
for _ in range(T):
    N, K = parse()
    D = [0]+parse()

    adj = [[] for _ in range(N+1)]
    memo = [None] * (N+1)
    for _ in range(K):
        X, Y = parse()
        adj[Y].append(X)
    W, = parse()

    print(solve(adj, D, W))
