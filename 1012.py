import sys
sys.setrecursionlimit(10**8)
def dfs(x, y, field, visited):
    visited[y][x] = True
    for dx in [-1, 0, +1]:
        newX = x+dx
        if newX < 0 or newX >= len(field[0]):
            continue
        if not visited[y][newX] and field[y][newX]:
            dfs(newX, y, field, visited)

    for dy in [-1, 0, +1]:
        newY = y+dy
        if newY < 0 or newY >= len(field):
            continue
        if not visited[newY][x] and field[newY][x]:
            dfs(x, newY, field, visited)

def main():
    T = int(input())
    for _ in range(T):
        M, N, K = map(int, input().split())
        field = [[False] * M for _ in range(N)]
        visited = [[False] * M for _ in range(N)]
        for _ in range(K):
            x, y = map(int, input().split())
            field[y][x] = True

        ret = 0
        for y in range(N):
            for x in range(M):
                if not visited[y][x] and field[y][x]:
                    ret += 1
                    dfs(x, y, field, visited)
        print(ret)
main()
