INF = float('inf')

n = int(input())
memo = [INF] * (n+1)
memo[1] = 0

for i in range(n):
    memo[i+1] = min(memo[i+1], memo[i]+1)
    if i*2 < n+1:
        memo[i*2] = min(memo[i*2], memo[i]+1)
    if i*3 < n+1:
        memo[i*3] = min(memo[i*3], memo[i]+1)

print(memo[n])
