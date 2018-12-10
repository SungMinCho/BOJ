#!/usr/local/bin/python3

def main():
  T = int(input())
  P = [0,1,1,1,2,2]

  for t in range(T):
    N = int(input())
    while len(P) < N+1:
      P.append(P[-1]+P[-5])
    print(P[N])

if __name__=="__main__":
  main()

