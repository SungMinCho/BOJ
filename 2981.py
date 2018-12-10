#!/usr/local/bin/python3

def gcd(a,b):
  if a<b: return gcd(b,a)
  if b==0: return a
  return gcd(b, a%b)

def lcm(a,b):
  return a//gcd(a,b)*b

def main():
  N = int(input())
  I = [int(input()) for i in range(N)]
  I.append(I[0])
  A = [abs(I[i+1]-I[i]) for i in range(N)]
  g = A[0]
  for i in range(1,N):
    g = gcd(g,A[i])

  ans = []
  back = [g]
  f = 2
  while f*f < g:
    if g % f == 0:
      ans.append(f)
      back.append(g//f)
    f += 1
  if g % f == 0: ans.append(f)

  back.reverse()
  ans.extend(back)
  for a in ans:
    print(a, end=' ')
  print()


if __name__=="__main__":
  main()
