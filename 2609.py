#!/usr/local/bin/python3

def gcd(a,b):
  if a<b: return gcd(b,a)
  if b==0: return a
  return gcd(b, a%b)

def lcm(a,b):
  return a//gcd(a,b)*b

def main():
  inp = [int(x) for x in input().split()]
  print(gcd(*inp))
  print(lcm(*inp))

if __name__=="__main__":
  main()
