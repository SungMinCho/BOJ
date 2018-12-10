#!/usr/local/bin/python3

left = {}
right = {}

def preorder(root):
  if root == '.':
    return
  print(root, end='')
  preorder(left[root])
  preorder(right[root])

def inorder(root):
  if root == '.':
    return
  inorder(left[root])
  print(root, end='')
  inorder(right[root])

def postorder(root):
  if root == '.':
    return
  postorder(left[root])
  postorder(right[root])
  print(root, end='')

def main():
  global left, right
  n = int(input())
  for i in range(n):
    a,l,r = input().split()
    left[a] = l
    right[a] = r

  preorder('A')
  print()
  inorder('A')
  print()
  postorder('A')
  print()

if __name__ == "__main__":
  main()
