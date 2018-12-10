#!/usr/local/bin/python3

def main():
  N = int(input())
  A = [0] + [int(x) for x in input().split()]
  d = [0] * (N+1)

  d[1] = A[1]
  for i in range(2, N+1):
    d[i] = max(A[i], A[i]+d[i-1])

  print(max(d[1:]))

if __name__=="__main__":
  main()
