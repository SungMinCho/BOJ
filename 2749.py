#!/usr/local/bin/python3

class mat:
  def __init__(self, m):
    self.m = m

  def __mul__(self, other):
    row = len(self.m)
    middle = len(other.m)
    col = len(other.m[0])

    m = [[0  for j in range(col)] for i in range(row)]

    for i in range(row):
      for j in range(col):
        for a in range(middle):
          m[i][j] += (self.m[i][a] * other.m[a][j]) % 1000000

    return mat(m)

def pow(M, n):
  if n == 1: return M
  M2 = pow(M, n//2)
  if n % 2 == 0:
    return M2*M2
  else:
    return M*M2*M2

def main():
  # (0 1) (Fn)     = (Fn+1)
  # (1 1) (Fn+1)    = (Fn+2)

  F = mat([[0,1],[1,1]])

  Zero = mat([[0],[1]])

  n = int(input())
  if n == 0:
    print(0)
  else:
    FN = pow(F, n)
    N = FN * Zero
    print(N.m[0][0])

if __name__ == "__main__":
  main()
