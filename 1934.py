#!/usr/local/bin/python3

def gcd(a,b):
  if a<b: return gcd(b,a)
  if b==0: return a
  return gcd(b, a%b)

def lcm(a,b):
  return a//gcd(a,b)*b

def main():
  for t in range(int(input())):
    print(lcm(*[int(x) for x in input().split()]))

if __name__=="__main__":
  main()
