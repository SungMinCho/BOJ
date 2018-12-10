#!/usr/local/bin/python3

def main():
  n = int(input())

  done = False

  for length in range(1, len(str(n))+1):
    lo = max(10**(length-1), n - (10**length-1))
    hi = min(10**length-1, n - 1)
    #print(lo, hi)
    #lo = 10**(length-1)
    #hi = 10**(length) - 1
    for i in range(lo, hi+1):
      if i + sum([int(x) for x in str(i)]) == n:
        done = True
        print(i)
        break
    if done:
      break

  if not done:
    print(0)

if __name__ == "__main__":
  main()
