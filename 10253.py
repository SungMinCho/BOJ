#!/usr/local/bin/python3

import math

def gcd(a,b):
  if a<b: return gcd(b,a)
  if b==0: return a
  return gcd(b, a%b)

def lcm(a,b):
  return a//gcd(a,b)*b

def main():
  T = int(input())
  for t in range(T):
    a, b = [int(x) for x in input().split()]
    while a > 1:
      x = math.ceil(b/a)
      l = lcm(b,x)
      a = a*(l//b) - (l//x)
      b = l
      g = gcd(a,b)
      a = a//g
      b = b//g
    print(b)

if __name__=="__main__":
  main()
