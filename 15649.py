def solve(cur, remain, notUsed):
    if remain == 0:
        print(" ".join(cur))
    else:
        for c in notUsed:
            solve(cur + [c], remain - 1, list(filter(lambda x: x != c, notUsed)))

N, M = map(int, input().split())
solve([], M, list(map(str, range(1, N+1))))
