#!/usr/local/bin/python3
from collections import defaultdict

def main():
  T = int(input())
  for t in range(T):
    Y,K = 0,0
    for i in range(9):
      y,k = [int(x) for x in input().split()]
      Y,K = Y+y, K+k
    if Y>K:
      print("Yonsei")
    elif Y<K:
      print("Korea")
    else:
      print("Draw")

if __name__=="__main__":
  main()
