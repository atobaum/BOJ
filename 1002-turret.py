def turret(inp):
  x1, y1, r1, x2, y2, r2 = inp
  d_square = (x1 - x2)**2 + (y1 - y2)**2
  r_square = (r1+r2)**2
  if d_square == 0:
    if r1 == r2:
      return -1
    else:
      return 0
  if d_square == r_square:
    return 1
  elif d_square < r_square:
    if d_square == (r1-r2)**2:
      return 1
    elif d_square < (r1-r2)**2: 
      return 0
    else:
      return 2
  else:
    return 0

n = int(input())
results = []
for _ in range(n):
  inp = map(int, input().split())
  results.append(turret(inp))
for res in results:
  print(res)