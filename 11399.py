def main():
    input()
    l = list(map(int, input().split()))
    l.sort()
    totalTime = 0
    curTime = 0
    for t in l:
        totalTime += curTime + t
        curTime += t
    print(totalTime)
main()
