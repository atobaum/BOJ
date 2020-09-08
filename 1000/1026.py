n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

b.sort()
a.sort(reverse=True)

ret = 0
for x, y in zip(a, b):
    ret += x * y
print(ret)
