#!/usr/local/bin/python3

def main():
  N = int(input())
  M = int(input())
  if M > 0:
    broken = [int(x) for x in input().split()]
  else:
    broken = []
  usable = [str(x) for x in range(10) if x not in broken]

  ans = abs(N-100)
  Ns = str(N)
  length = len(Ns)
  cand = []

  SAME = 0
  LOW = 1
  HIGH = 2

  def under(u):
    return [c for c in usable if c < u]
  def over(u):
    return [c for c in usable if c > u]

  def backtrack(at, s, comp, leadingZeros):
    if at == length:
      if leadingZeros and '0' not in usable: return
      cand.append(s)
      return
    if comp == SAME:
      if Ns[at] in usable:
        backtrack(at+1, s+Ns[at], SAME, leadingZeros and Ns[at]=='0')
      low = under(Ns[at])
      if leadingZeros:
        low.append('0')
      if len(low) > 0:
        m = max(low)
        backtrack(at+1, s+m, LOW if Ns[at] > '0' else SAME, leadingZeros and m=='0')
      high = over(Ns[at])
      if len(high) > 0:
        m = min(high)
        backtrack(at+1, s+m, HIGH, leadingZeros and m=='0')
    elif comp == LOW:
      m = max(usable)
      backtrack(at+1, s+m, LOW, leadingZeros and m=='0')
    else:
      m = min(usable)
      backtrack(at+1, s+m, HIGH, leadingZeros and m=='0')



  if len(usable) > 0:
    backtrack(0, "", SAME, True)
    nozero = [u for u in usable if u != '0']
    if len(nozero) > 0:
      backtrack(0, min(nozero), HIGH, False)

  def click(c):
    index = 0
    while index < len(c) and c[index] == '0':
      index += 1
    ret = len(c) - index
    if ret == 0: return 1
    return ret

  for c in cand:
    ans = min(ans, click(c)+abs(N-int(c)))

  print(ans)


if __name__=="__main__":
  main()
