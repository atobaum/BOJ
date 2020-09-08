# 수2
def main():
    L = int(input())
    luckySet = list(map(int, input().split()))
    luckySet.sort()
    N = int(input())
    if N in luckySet:
        print(0)
        return

    a = 0
    b = luckySet[0]

    for i, v in enumerate(luckySet):
        if v > N:
            break
    if i > 0:
        a = luckySet[i-1]
    b = luckySet[i]

    # -1은 중복된 [N, N]
    res = (N-a)*(b-N) - 1
    print(res)

main()
