#!/usr/local/bin/python3

def main():
  m = 0
  ms = []
  for t in range(4):
    a,b = [int(x) for x in input().split()]
    m = m+b-a
    ms.append(m)
  print(max(ms))

if __name__=="__main__":
  main()
