#!/usr/local/bin/python3
from collections import defaultdict

length = 0
done = False
ans = None

cnt = 0
cntgoal = 0

mem = defaultdict(lambda:{}) # mem[i][j] = count of dfs starting from i(0~9) with length j(1~)

combmem = defaultdict(lambda:{})

def comb(i,j):
  if i < j:
    return 0
  if j == 0 or j == i:
    return 1
  if i == 0:
    return 0

  if j in combmem[i]:
    return combmem[i][j]

  val = comb(i-1,j) + comb(i-1,j-1)
  combmem[i][j] = val
  return val

def dfs(at, s):
  global length, done, ans, cnt, cntgoal
  if at == length:
    cnt += 1
    if cnt == cntgoal:
      ans = s
      done = True
    return

  if at == 0:
    todigit = 9
    fromdigit = 1
  else:
    todigit = int(s[-1])-1
    fromdigit = 0

  for i in range(fromdigit, todigit+1):
    memi, memj = i, length-at
    if memj not in mem[memi]:
      # length = memj / digit start from memi =  Comb(memi, memj-1)
      mem[memi][memj] = comb(memi, memj-1)
    c = mem[memi][memj]
    #print('start digit ', memi, ' length ', memj, ' c ', c)
    if cnt + c < cntgoal:
      cnt += c
      continue
    else:
      dfs(at+1, s+str(i))
    if done:
      return

def main():
  global cntgoal, length, done, ans
  cntgoal = int(input())

  if cntgoal == 0:
    print(0)
    return

  for length in range(1,11):
    dfs(0, "")
    if done:
      break
  if done:
    print(ans)
  else:
    print(-1)

if __name__ == "__main__":
  main()
