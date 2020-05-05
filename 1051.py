def solve(mapp):
    Y, X = map(len, [mapp, mapp[0]])
    maxLength = 0
    for sY in range(Y):
        for sX in range(X):
            length = 0
            while sX + length < X and sY + length < Y:
                if (mapp[sY][sX] == mapp[sY+length][sX]) and (mapp[sY][sX] == mapp[sY][sX+length]) and (mapp[sY+length][sX+length] == mapp[sY][sX]):
                    maxLength = max(maxLength, length+1)
                length += 1
    return maxLength ** 2



def main():
    N, M = map(int, input().split())
    mapp = []
    for _ in range(N):
        mapp.append([int(c) for c in input()])
    print(solve(mapp))

main()
