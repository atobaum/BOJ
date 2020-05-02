def solve(cur, remain, notUsed):
    if remain > len(notUsed):
        return
    elif remain == 0:
        print(" ".join(cur))
    else:
        for i, c in enumerate(notUsed):
            solve(cur + [c], remain - 1, notUsed[i+1:])

N, M = map(int, input().split())
solve([], M, list(map(str, range(1, N+1))))
