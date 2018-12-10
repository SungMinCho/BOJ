#!/usr/local/bin/python3
import math

def main():
  m = int(input())
  n = int(input())
  ans = []
  s = math.sqrt(m)
  s = math.floor(s)
  if s*s < m:
    s += 1

  while m <= s*s <= n:
    ans.append(s*s)
    s += 1

  if len(ans) == 0:
    print(-1)
  else:
    print(sum(ans))
    print(ans[0])

if __name__ == "__main__":
  main()
