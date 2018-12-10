#!/usr/local/bin/python3

def main():
  n,k = [int(x) for x in input().split()]
  coins = [int(input()) for i in range(n)]

  # d[k][i] : make k using i~n-1 : (i = 0~n-1)
  # d[k][i] = sum of d[k-coins[i]*n][i+1]

  d = [[0 for j in range(n)] for i in range(k+1)]

  for make in range(k+1):
    for i in range(n-1, -1, -1):
      # make make using i~n-1
      # use only i
      if make % coins[i] == 0: d[make][i] = 1

      # use i and i+1~n-1
      if i == n-1: continue
      m = make
      while m > 0:
        d[make][i] += d[m][i+1]
        m -= coins[i]

  print(d[k][0])

if __name__=="__main__":
  main()
