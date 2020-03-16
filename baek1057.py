# 2020.1.16 solved

n, a, b = list(map(int, input().split()))
round = 1
chunk = 2

while True:
    if int((a-1) / chunk) == int((b-1) / chunk):
        break
    round += 1
    chunk *= 2

print(round)
