#!/usr/local/bin/python3

def main():
  d = ['D','C','B','A','E']
  for i in range(3):
    s = sum(int(x) for x in input().split())
    print(d[s])

if __name__=="__main__":
  main()
