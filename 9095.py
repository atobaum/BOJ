def solve(n):
    if n == 0:
        return 1
    else:
        ret = solve(n-1)
        if n > 1:
            ret += solve(n-2)
        if n > 2:
            ret += solve(n-3)
        return ret

T = int(input())
for _ in range(T):
    n = int(input())
    print(solve(n))
