#!/usr/local/bin/python3

def main():
  M = int(input())
  cup = [0,1,2,3]
  for i in range(M):
    a,b = [int(x) for x in input().split()]
    cup[a],cup[b] = cup[b],cup[a]
  print(cup.index(1))

if __name__=="__main__":
  main()
