#!/usr/local/bin/python3
from collections import defaultdict

class Disjoint:
  def __init__(self):
    self.parent = {}
    self.shortest = {}
    self.rank = {}
    self.intValue = {}
    self.contradiction = False

  def find(self, name):
    if self.parent[name] == name:
      return name
    ret = self.find(self.parent[name])
    self.parent[name] = ret
    return ret

  def findShortest(self, name):
    return self.shortest[self.find(name)]

  def add(self, name):
    if name not in self.parent:
      self.parent[name] = name
      self.shortest[name] = name
      self.rank[name] = 1
      if name.isdigit() or name[0] == '-':
        self.intValue[name] = name

  def merge(self, a, b):
    ra = self.find(a)
    rb = self.find(b)
    if self.rank[ra] > self.rank[rb]:
      ra,rb = rb,ra
    self.parent[ra] = rb
    if self.rank[ra] == self.rank[rb]:
      self.rank[rb] += 1
    if len(self.shortest[ra]) < len(self.shortest[rb]):
      self.shortest[rb] = self.shortest[ra]
    if ra in self.intValue and rb in self.intValue:
      if self.intValue[ra] != self.intValue[rb]:
        return False # contradiction
    elif ra in self.intValue:
      self.intValue[rb] = self.intValue[ra]
    return True


def short(logics):
  dj = Disjoint()
  different = defaultdict(lambda : set())
  for logic in logics:
    if "==" in logic:
      a,b = logic.split("==")
      dj.add(a)
      dj.add(b)
      if not dj.merge(a, b):
        return "0==1"
    else:
      a,b = logic.split("!=")
      dj.add(a)
      dj.add(b)
      different[a].add(b)

  res = set()
  # same
  for name in dj.parent:
    shortest = dj.findShortest(name)
    if name != shortest:
      res.add(name + '==' + shortest)

  # different
  for a,sb in different.items():
    for b in sb:
      ra = dj.find(a)
      rb = dj.find(b)
      if ra in dj.intValue and rb in dj.intValue:
        if dj.intValue[ra] != dj.intValue[rb]:
          continue
        else:
          return "0==1"
      shorta = dj.findShortest(a)
      shortb = dj.findShortest(b)
      if shorta == shortb:
        return "0==1"
      if shorta > shortb:
        shorta, shortb = shortb, shorta
      res.add(shorta + "!=" + shortb)

  if len(res) == 0:
    return "0==0"
  else:
    return "&&".join(list(res))

def main():
  logics = input().split("&&")
  print(short(logics))

if __name__=="__main__":
  main()
