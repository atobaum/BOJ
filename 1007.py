def squareSum(a, b):
    return a ** 2 + b ** 2

def solve(pts, sumX, sumY, remain):
    if remain == 0:
        return squareSum(sumX, sumY)
    elif len(pts) < remain:
        return float('inf')
    else:
        notSelected = solve(pts[1:], sumX, sumY, remain)
        selected = solve(pts[1:], sumX - 2 * pts[0][0], sumY - 2 * pts[0][1], remain - 1)
        return min(notSelected, selected)

def main():
    T = int(input())
    for _ in range(T):
        N = int(input())
        pts = []
        sumX = 0
        sumY = 0
        for _ in range(N):
            pt = list(map(int, input().split()))
            pts.append(pt)
            sumX += pt[0]
            sumY += pt[1]
        print(solve(pts, sumX, sumY, len(pts)//2) ** (1/2))

main()
