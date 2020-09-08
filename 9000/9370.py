import sys
from queue import PriorityQueue
INF = float('inf')

def parse():
    return list(map(int, sys.stdin.readline().split()))

def solve(adj, s, dest, g, h):
    q = PriorityQueue() #(cost: int, here: int, through_g-h: boolean)
    dist = [INF] * len(adj)

    q.put((0, s, False))
    ret = []
    
    while (not q.empty()) or len(dest) != 0:
        cost, here, through = q.get()
        if here in dest:
            if through:
                ret.append(here)
            dest.pop(dest.index(here))

        for there, nextCost in adj[here]:
            if dist[there] > cost + nextCost:
                dist[there] = nextCost
                if (here in [h, g]) and (there in [h, g]):
                    through = True
                q.put((cost+nextCost, there, through))

    ret.sort()
    return ret

T, = parse()

for _ in range(T):
    n, m, t = parse()
    s, g, h = parse()

    adj = [[] for _ in range(n+1)]
    dest = []
    for _ in range(m):
        a, b, d = parse()
        adj[a].append((b, d))
        adj[b].append((a, d))

    for _ in range(t):
        x, = parse()
        dest.append(x)

    ret = [str(x) for x in solve(adj, s, dest, g, h)]
    print(" ".join(ret))
