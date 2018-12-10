#!/usr/local/bin/python3

def gcd(a,b):
  if a<b: return gcd(b,a)
  if b==0: return a
  return gcd(b, a%b)

def lcm(a,b):
  return a//gcd(a,b)*b

def main():
  N = int(input())
  I = [int(x) for x in input().split()]
  for i in range(1, N):
    g = gcd(I[0], I[i])
    print(I[0]//g, '/', I[i]//g, sep='')

if __name__=="__main__":
  main()
