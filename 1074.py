#!/usr/local/bin/python3

r,c = 0,0
visited = False

def visit(I,J,L):
  global r, c, visited
  if I <= r < I+L and J <= c < J+L:
    if L == 1:
      visited = True
      return 1
    L2 = L // 2
    ret = 0
    for i,j in [(0,0),(0,1),(1,0),(1,1)]:
      ret += visit(I+i*L2, J+j*L2, L2)
    return ret
  else:
    if visited:
      return 0
    else:
      return L*L

def main():
  global r,c
  n,r,c = [int(x) for x in input().split()]
  n = 2**n

  print(visit(0,0,n)-1)

if __name__ == "__main__":
  main()
