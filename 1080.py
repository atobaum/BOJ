from itertools import chain 

def solve():
    n, m = map(int, input().split())

    A = []
    B = []
    diff = []

    for _ in range(n):
        A.append(list(map(int, input())))

    for _ in range(n):
        B.append(list(map(int, input())))

    # under 3x3
    if n < 3 or m < 3:
        if A == B:
            return 0
        else:
            return -1

    answer = 0
    for y in range(n-2):
        for x in range(m-2):
            if A[y][x] != B[y][x]:
                answer += 1
                for dy in range(3):
                    for dx in range(3):
                        A[y+dy][x+dx] = 1-A[y+dy][x+dx]
    if A == B:
        return answer
    else:
        return -1

print(solve())
