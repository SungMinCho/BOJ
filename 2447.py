#!/usr/local/bin/python3


def main():
  n = int(input())
  length = 1
  s = ["*"]

  while length < n:
    # s is array[length] of string[length]
    blank = " " * length
    ss = []
    for row in s:
      ss.append(row*3)

    for row in s:
      ss.append(row + blank + row)

    for row in s:
      ss.append(row*3)

    s = ss
    length *= 3

  print('\n'.join(s))

if __name__ == "__main__":
  main()
