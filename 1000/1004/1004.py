import sys

def parse():
    return list(map(int, sys.stdin.readline().split()))

def distSq(a, b):
    return (a[0] - b[0])**2 +(a[1] - b[1])**2

def solve(a, b, planets):
    ret = 0
    for planet in planets:
        r2 = planet[2]**2
        d1 = distSq(a, planet)
        d2 = distSq(b, planet)

        if (d1<r2 and d2>r2) or (d1>r2 and d2<r2):
            ret += 1
    return ret

t, = parse()
for _ in range(t):
    x1, y1, x2, y2 = parse()
    n, = parse()
    planets = []
    for _ in range(n):
        planets.append(parse())
    print(solve([x1, y1], [x2, y2], planets))

