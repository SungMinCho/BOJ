#!/usr/local/bin/python3

def main():
  n = int(input())

  wh = [[int(x) for x in input().split()] for i in range(n)]

  for i in range(n):
    k=0
    for j in range(n):
      if j == i: continue
      if wh[i][0] < wh[j][0] and wh[i][1] < wh[j][1]:
        k += 1
    print(k+1, end=' ')
  print()

if __name__ == "__main__":
  main()
