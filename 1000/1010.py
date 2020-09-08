# 20200811 binomial
binom_memo = [[-1]*30 for _ in range(30)]

def binom(n, m):
    if n == m or m == 0:
        return 1
    if binom_memo[n][m] != -1:
        return binom_memo[n][m]
    res = binom(n-1, m)+binom(n-1, m-1)
    binom_memo[n][m] = res
    return res

T = int(input())
for _ in range(T):
    n, m = list(map(int, input().split()))
    print(binom(m, n))
