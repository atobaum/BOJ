from queue import PriorityQueue
import sys

def parse():
    return list(map(int,sys.stdin.readline().split()))

def dji(adj, s, e):
    q = PriorityQueue()
    q.put((0, s))

    while not q.empty():
        cost, here = q.get()
        if here == e:
            return cost
        for there, deltaCost in adj[here]:
            q.put((cost+deltaCost, there))

n, = parse()
m, = parse()

adj = [[] for _ in range(m)]
for _ in range(m):
    a, b, c = parse()
    adj[a].append((b, c))

s, e = parse()
print(dji(adj, s, e))
