#!/usr/local/bin/python3

def main():
  n,m = [int(x) for x in input().split()]
  m1 = [[int(x) for x in input().split()] for i in range(n)]

  _,k = [int(x) for x in input().split()]
  m2 = [[int(x) for x in input().split()] for i in range(m)]

  m3 = [[0 for j in range(k)] for i in range(n)]

  for i in range(n):
    for j in range(k):
      for a in range(m):
        m3[i][j] += m1[i][a] * m2[a][j]

  for row in m3:
    print(*row)

if __name__=="__main__":
  main()
