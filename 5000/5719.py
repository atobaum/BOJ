import sys
from queue import PriorityQueue

INF = float('inf')

def parse():
    return list(map(int, sys.stdin.readline().split()))

def dij(adj, S, D):
    q = PriorityQueue()
    dist = [INF for _ in range(len(adj))]

    dist[S] = 0
    q.put((0, S))
    while not q.empty():
        cost, cur = q.get()
        if cur == D:
            break

        for to, nextCost in adj[cur]:
            if cost + nextCost < dist[to]:
                dist[to] = cost + nextCost
                q.put((cost+nextCost, to))

    return dist

def solve():
    N, M = parse()
    if N == 0 and M == 0:
        return
    S, D = parse()
    adj = [[] for _ in range(N)]
    backAdj = [[] for _ in range(N)]
    for _ in range(M):
        U, V, P = parse()
        adj[U].append((V, P))
        backAdj[V].append((U, P))

    dist = dij(adj, S, D)

    minCost = dist[D]
    if minCost == INF:
        print(-1)
        return True

    q = [D]
    while len(q) > 0:
        cur = q.pop(0)
        for fr, nextCost in backAdj[cur]:
            if dist[cur] == dist[fr] + nextCost:
                adj[fr] = list(filter(lambda x: x[0] != cur, adj[fr]))
                q.append(fr)

    dist = dij(adj, S, D)
    ret = dist[D]
    if ret == INF:
        print(-1)
    else:
        print(ret)
    return True

    while True:
        if cost == -1:
            break
        if minCost == 0:
            minCost = cost
        if minCost < cost:
            break
        paths.append(path)
        for idx, (to, c) in enumerate(adj[path[1]]):
            if to == D:
                adj[path[1]].pop(idx)
                break

    for path in paths:
        for idx in range(1, len(path)-1):
            a, b = path[idx+1], path[idx]
            for i, (to, c) in enumerate(adj[a]):
                if to == b:
                    adj[a].pop(i)
                    break

    cost, path = dij(adj, S, D, False)
    print(cost)
    return True

def main():
    while solve():
        pass

main()
