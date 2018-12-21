#!/usr/local/bin/python3
from random import *
from subprocess import run, PIPE
import networkx as nx
from matplotlib import pyplot as plt
import time

def comp():
  cmd = 'g++ -std=c++14 -o main.out main.cpp'
  run(cmd.split())

def runPgm(name, inp):
  start = time.time()
  p = run([name], stdout=PIPE, input=inp, encoding='ascii')
  end = time.time()
  print('elapsed :', end-start)
  return p.stdout.strip()

def runMain(inp):
  return runPgm('./main.out', inp)

def makeInp(N, bound):
  inp = []
  d = {}
  for i in range(N):
    x,y = randint(-bound,bound), randint(-bound,bound)
    while (x,y) in d:
      x,y = randint(-bound, bound), randint(-bound, bound)
    inp.append((x,y))
    d[(x,y)] = True
  return inp

def points2str(inp):
  return '\n'.join(' '.join(str(x) for x in p) for p in inp)

def str2points(s):
  return [tuple(int(x) for x in line.split()) for line in s.split('\n')]

def drawResult(points, hullpoints):
  G = nx.Graph()
  for i in range(len(points)):
    G.add_node(i, pos=points[i])
  for i in range(len(hullpoints)):
    hi = points.index(hullpoints[i])
    hj = points.index(hullpoints[i+1 if i+1 < len(hullpoints) else 0])
    G.add_edge(hi, hj)
  pos = nx.get_node_attributes(G,'pos')
  nx.draw(G,pos,node_size=[1]*len(points))

def main():
  comp()
  N, bound = 200000, 10000000
  inp = makeInp(N,bound)
  inpstr = "1\n" + str(N) + "\n" + points2str(inp)
  outstr = runMain(inpstr)
  output = str2points(outstr)
  drawResult(inp, output)
  plt.show()


if __name__ == "__main__":
  main()
