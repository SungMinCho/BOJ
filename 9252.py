#!/usr/local/bin/python3

def main():
  s1 = "?" + input()
  s2 = "?" + input()
  n,m = len(s1), len(s2)
  d = [[0 for j in range(m)] for i in range(n)]
  follow = [[None for j in range(m)] for i in range(n)]

  for i in range(1, n):
    for j in range(1, m):
      r = d[i][j-1]
      follow[i][j] = 2
      if d[i-1][j] > r:
        r = d[i-1][j]
        follow[i][j] = 1
      if s1[i] == s2[j] and 1+d[i-1][j-1] > r:
        r = 1 + d[i-1][j-1]
        follow[i][j] = 3
      d[i][j] = r


  s = ""
  i, j = n-1, m-1
  while i > 0 and j > 0:
    f = follow[i][j]
    if f == 3:
      s = s1[i] + s
      i,j, = i-1,j-1
    elif f == 2:
      j -= 1
    else:
      i -= 1


  print(d[n-1][m-1])
  print(s)


if __name__=="__main__":
  main()
