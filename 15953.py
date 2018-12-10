#!/usr/local/bin/python3

def won(a,b):
  ret = 0
  if a == 0:
    pass
  elif a <= 1:
    ret += 5000000
  elif a <= 1+2:
    ret += 3000000
  elif a <= 1+2+3:
    ret += 2000000
  elif a <= 1+2+3+4:
    ret += 500000
  elif a <= 1+2+3+4+5:
    ret += 300000
  elif a <= 1+2+3+4+5+6:
    ret += 100000

  if b == 0:
    pass
  elif b <= 1:
    ret += 5120000
  elif b <= 1+2:
    ret += 2560000
  elif b <= 1+2+4:
    ret += 1280000
  elif b <= 1+2+4+8:
    ret += 640000
  elif b <= 1+2+4+8+16:
    ret += 320000

  return ret

def main():
  T = int(input())
  for i in range(T):
    a,b = [int(x) for x in input().split()]
    print(won(a,b))

if __name__=="__main__":
  main()
