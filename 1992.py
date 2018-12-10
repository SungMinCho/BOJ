#!/usr/local/bin/python3

n = 0
board = None

def compress(I, J, L):
  global board
  val = board[I][J]
  if L == 1:
    print(val, end='')
    return

  allsame = True
  for i in range(I, I+L):
    for j in range(J, J+L):
      if val != board[i][j]:
        allsame = False
        break
    if not allsame:
      break

  if allsame:
    print(val, end='')
  else:
    print('(', end='')
    for i in range(2):
      for j in range(2):
        compress(I+i*L//2, J+j*L//2, L//2)
    print(')', end='')

def main():
  global n, board
  n = int(input())
  board = [input() for i in range(n)]
  compress(0,0,n)
  print()

if __name__ == "__main__":
  main()
