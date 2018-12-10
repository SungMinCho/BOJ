#!/usr/local/bin/python3

def main():
  A,B,C = [int(input()) for i in range(3)]
  digits = [chr(i) for i in range(ord('0'), ord('9')+1)]
  s = str(A*B*C)
  dic = {}
  for d in digits:
    dic[d] = 0
  for d in s:
    dic[d] += 1
  for d in digits:
    print(dic[d])

if __name__=="__main__":
  main()
