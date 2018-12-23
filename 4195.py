#!/usr/local/bin/python3

class DS:
  def __init__(self):
    self.parent = {}
    self.size = {}
  
  def root(self, a):
    if a == self.parent[a]:
      return a
    ret = self.root(self.parent[a])
    self.parent[a] = ret
    return ret
  
  def merge(self, a, b):
    if a not in self.parent:
      self.parent[a] = a
      self.size[a] = 1
    if b not in self.parent:
      self.parent[b] = b
      self.size[b] = 1
    ra = self.root(a)
    rb = self.root(b)
    if ra != rb:
      self.parent[ra] = rb
      self.size[rb] += self.size[ra]
  
  def getSize(self, a):
    return self.size[self.root(a)]

for t in range(int(input())):
  n = int(input())
  name2int = {}
  idcnt = 0
  ds = DS()

  for i in range(n):
    name1, name2 = input().split()
    if name1 not in name2int:
      idcnt += 1
      name2int[name1] = idcnt
    if name2 not in name2int:
      idcnt += 1
      name2int[name2] = idcnt
  
    ds.merge(name2int[name1], name2int[name2])
    print(ds.getSize(name2int[name1]))