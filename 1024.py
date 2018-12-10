#!/usr/local/bin/python3

def sum(L, start):
  ret = L*(L-1)/2 + L*start

def main():
  N,L = [int(x) for x in input().split()]
  for l in range(L, 101):
    if (N - l*(l-1)//2) % l == 0:
      start = (N - l*(l-1)//2) // l
      if start < 0: continue
      for k in range(l):
        print(start, end=' ')
        start += 1
      print()
      break
  else:
    print(-1)

if __name__=="__main__":
  main()
