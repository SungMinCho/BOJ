#!/usr/local/bin/python3


def main():
  n = int(input())
  length = 3
  s = ["*", "* *", "*****"]
  baselength = 5

  while length < n:
    # s is array[length] of string[length]
    blank = " " * length
    ss = []
    for row in s:
      ss.append(row)
    bl = baselength
    for row in s:
      ss.append(row + " "*bl + row)
      bl -= 2
    baselength = baselength*2 + 1

    s = ss
    length *= 2

  length -= 1
  for row in s:
    for i in range(length):
      print(" ", end='')
    print(row, end='')
    for i in range(length):
      print(" ", end='')
    print()
    length -= 1

if __name__ == "__main__":
  main()
