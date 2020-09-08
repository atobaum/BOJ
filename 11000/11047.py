import sys
def main():
    N, K = map(int, input().split())
    coins = []
    for _ in range(N):
        coins.append(int(input()))

    curTotal = 0
    ret = 0
    for i in range(N-1, -1, -1):
        coin = coins[i]
        n = int((K-curTotal)/coin)
        curTotal += coin * n
        ret += n
        if curTotal == K:
            return ret

print(main())
