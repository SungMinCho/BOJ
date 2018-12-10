#!/usr/local/bin/python3
import math
from decimal import Decimal

def min_std(N, K, ns):
  #ns.sort()
  psum = [Decimal(0)]
  psqsum = [Decimal(0)]
  for n in ns:
    psum.append(psum[-1]+n)
    psqsum.append(psqsum[-1]+n*n)

  """
  mean((a-m)^2) = mean(a^2 - 2am + m^2) =  mean(a^2) - m*2
  """
  def getVar(a, k):
    # var of ns[a+1] ~ ns[a+k]
    mean = (psum[a+k] - psum[a]) / k
    sqmean = (psqsum[a+k] - psqsum[a]) / k
    return sqmean - mean*mean

  minvar = getVar(0,K)

  for k in range(K, N+1):
    for i in range(N-k+1):
      minvar = min(minvar, getVar(i, k))

  std = math.sqrt(minvar)
  return std


def main():
  N,K = [int(x) for x in input().split()]
  ns = [int(x) for x in input().split()]
  print(min_std(N, K, ns))

if __name__=="__main__":
  main()
