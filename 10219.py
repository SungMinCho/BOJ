#!/usr/local/bin/python3

def main():
  T = int(input())
  for t in range(T):
    H,W = [int(x) for x in input().split()]
    meats = [input() for i in range(H)]
    for m in meats:
      print(m[::-1])

if __name__=="__main__":
  main()
