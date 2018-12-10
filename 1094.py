#!/usr/local/bin/python3

def main():
  stick = [64]
  X = int(input())
  while sum(stick) > X:
    stick.append(stick[-1]/2)
    stick[-2] = stick[-1]
    if sum(stick[:-1]) >= X:
      stick = stick[:-1]
  print(len(stick))

if __name__=="__main__":
  main()
