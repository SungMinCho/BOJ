#!/usr/local/bin/python3
from collections import defaultdict
from decimal import Decimal

def main():
  N = int(input())
  d = [[0 for j in range(10)] for i in range(N+1)]

  for i in range(10):
    d[1][i] = 1
  for i in range(2, N+1):
    d[i][0] = d[i-1][1]
    d[i][9] = d[i-1][8]
    for j in range(1,9):
      d[i][j] = d[i-1][j-1] + d[i-1][j+1]
    for j in range(10):
      d[i][j] = d[i][j] % 1000000000

  print(sum(d[N][1:]) % 1000000000)

if __name__=="__main__":
  main()
