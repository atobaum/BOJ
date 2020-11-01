def lowerbound(li, v):
    if v > li[-1]:
        return None
    if v <= li[0]:
        return 0
    low = 0
    high = len(li)

    while high - low < 2:
        mid = (low + high) // 2
        if li[mid] < v:
            high = mid
        else:
            low = mid

    return low 

def main():
    N, K = map(int, input().split())
    gems = []
    packs = []

    for _ in range(N):
        M, V = map(int, input().split())
        gems.append((V, M))

    for _ in range(K):
        packs.append(int(input()))

    gems.sort(reverse = True)
    packs.sort()

    res = 0

    for V, M in gems:
        pack_idx = lowerbound(packs, M)
        if not pack_idx == None:
            packs.pop(pack_idx)
            res += V
        if len(packs) == 0:
            break

    print(res)

main()
