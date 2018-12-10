#!/usr/local/bin/python3

def main():
  N,X = [int(x) for x in input().split()]
  answer = [x for x in input().split() if int(x) < X]
  print(' '.join(answer))

if __name__=="__main__":
  main()
