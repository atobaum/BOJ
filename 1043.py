def parse():
    return list(map(int, input().split()))

def dfs(adj, visited, i):
    visited[i] = True
    for to in adj[i]:
        if not visited[to]:
            dfs(adj, visited, to)

def solve():
    adj = [[] for _ in range(101)]
    n, m = parse()
    known = parse()[1:]

    for party in range(51, 51+m):
        members = parse()[1:]
        adj[party] = members
        for mem in members:
            adj[mem].append(party)

    visited = [False] * 101
    for mem in known:
        dfs(adj, visited, mem)

    ret = visited[51:51+m].count(False)
    print(ret)
solve()
