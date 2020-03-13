# 색칠해야할 개수 구하기
def leastNumber(board):
  default = board[0][0]
  count = 0
  for rowInx, row in enumerate(board):
    for colIdx, x in enumerate(row):
      if (x + rowInx + colIdx) % 2 == default:
        count += 1
  return min(count, 64-count)
  
N, M = map(int, input().split())
board = [] # board
for _ in range(N):
  board.append(list(map(lambda x: 1 if x == 'W' else 0, input())))
m = 64 # 최소 색칠 개수

for i in range(N-7):
  for j in range(M-7):
    tempBoard = []
    for row in board[i:i+8]:
      tempBoard.append(row[j:j+8])
    m = min(m, leastNumber(tempBoard))

print(m)

