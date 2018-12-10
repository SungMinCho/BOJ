#!/usr/local/bin/python3
import math

def main():
  keys = [int(input()) for i in range(9)]
  s = sum(keys)
  done = False

  for i in range(8):
    for j in range(i+1, 9):
      if s - keys[i] - keys[j] == 100:
        done = True
        a, b = keys[i], keys[j]
        keys.remove(a)
        keys.remove(b)
        keys.sort()
        for k in keys:
          print(k)
        break
    if done:
      break

if __name__ == "__main__":
  main()
