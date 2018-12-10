#!/usr/local/bin/python3
from collections import defaultdict
from decimal import Decimal

def main():
  teams = input().split()
  d = {a:{b:None for b in teams} for a in teams}
  for i in range(6):
    A,B,W,D,L = input().split()
    W,D,L = Decimal(W),Decimal(D),Decimal(L)
    d[A][B] = [W,D,L]
    d[B][A] = [L,D,W]

  score = {a : 0 for a in teams}

  winprob = {a : Decimal(0.0) for a in teams}

  def update(prob):
    s = list(score.items())
    s.sort(key=lambda x : -x[1])
    names = [x[0] for x in s]
    n = [x[1] for x in s]
    if n[0] == n[1] == n[2] == n[3]:
      for name in names:
        winprob[name] += prob * Decimal(0.5)
    elif n[0] == n[1] == n[2] > n[3]:
      for name in names[:3]:
        winprob[name] += prob * Decimal(2.0)/Decimal(3.0)
    elif n[0] > n[1] == n[2] == n[3]:
      winprob[names[0]] += prob
      for name in names[1:]:
        winprob[name] += prob * Decimal(1.0)/Decimal(3.0)
    elif n[0] > n[1] == n[2] > n[3]:
      winprob[names[0]] += prob
      for name in names[1:3]:
        winprob[name] += prob * Decimal(0.5)
    else:
      for name in names[:2]:
        winprob[name] += prob

  def dfs(i,j,prob):
    if i == 3:
      update(prob)
      return
    nexti, nextj = i, j+1
    if nextj == 4:
      nexti, nextj = i+1, i+2
    # i win j
    score[teams[i]] += 3
    dfs(nexti, nextj, prob*d[teams[i]][teams[j]][0])
    score[teams[i]] -= 3

    # i draw j
    score[teams[i]] += 1
    score[teams[j]] += 1
    dfs(nexti, nextj, prob*d[teams[i]][teams[j]][1])
    score[teams[i]] -= 1
    score[teams[j]] -= 1

    # i lose j
    score[teams[j]] += 3
    dfs(nexti, nextj, prob*d[teams[i]][teams[j]][2])
    score[teams[j]] -= 3

  dfs(0, 1, Decimal(1.0))

  for t in teams:
    print(winprob[t])

if __name__=="__main__":
  main()
