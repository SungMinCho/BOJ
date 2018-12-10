#!/usr/local/bin/python3

def main():
  s1 = "?" + input()
  s2 = "?" + input()
  n,m = len(s1), len(s2)
  d = [[0 for j in range(m)] for i in range(n)]

  for i in range(1, n):
    for j in range(1, m):
      r = 0
      if s1[i] == s2[j]: r = max(r, 1+d[i-1][j-1])
      r = max(r, d[i][j-1], d[i-1][j])
      d[i][j] = r

  print(d[n-1][m-1])


if __name__=="__main__":
  main()
