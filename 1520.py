#!/usr/local/bin/python3

board = None
mem = None
N = 0
M = 0

def get(i, j):
  if mem[i][j] != -1: return mem[i][j]

  ret = 0
  for io,jo in [(0,1),(0,-1),(1,0),(-1,0)]:
    newi, newj = i+io, j+jo
    if newi < 0 or newi >= N or newj < 0 or newj >= M: continue
    if board[newi][newj] > board[i][j]:
      ret += get(newi, newj)
  mem[i][j] = ret
  return ret


def main():
  global board, mem, N, M
  N,M = [int(x) for x in input().split()]
  board = [None for i in range(N)]
  for i in range(N):
    board[i] = [int(x) for x in input().split()]

  mem = [[-1 for j in range(M)] for i in range(N)]
  mem[0][0] = 1

  print(get(N-1,M-1))

if __name__=="__main__":
  main()
