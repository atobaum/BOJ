# 가장 큰 약수와 가장 작은 약수 곱하기
input()
divs = map(int, input().split())
max = 1
min = 2**32-1
for div in divs:
  if div < min:
    min = div
  if div > max:
    max = div
print(max*min)