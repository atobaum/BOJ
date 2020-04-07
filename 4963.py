import sys
sys.setrecursionlimit(10**6)

def parse():
    return list(map(int, input().split()))

def solve(l):
    w = len(l)+2
    h = len(l[0])+2
    l = [[0]*h] + [[0] + row + [0] for row in l] + [[0]*h]
    visited = [[False] * h for _ in range(w)]
    ret = 0

    def dfs(x, y):
        visited[x][y] = True
        for dx in [-1, 0, 1]:
            for dy in [-1, 0, 1]:
                if dx == 0 and dy == 0:
                    continue
                if l[x+dx][y+dy] == 1 and visited[x+dx][y+dy] == False:
                    dfs(x+dx, y+dy)

    for x in range(w):
        for y in range(h):
            if l[x][y] == 1 and visited[x][y] == False:
                ret += 1
                dfs(x, y)

    return ret

while True:
    w, h = parse()
    if w == 0 and h == 0:
        break
    l = []
    for _ in range(h):
        l.append(parse())
    print(solve(l))
