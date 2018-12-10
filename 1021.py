#!/usr/local/bin/python3

def main():
  N,M = [int(x) for x in input().split()]
  ks = [int(x)-1 for x in input().split()]
  q = [k for k in range(N)]

  ans = 0
  for i in range(M):
    index = q.index(ks[i])
    ans += min(index, len(q) - index)
    q = q[index+1:] + q[:index]
  print(ans)

if __name__=="__main__":
  main()
