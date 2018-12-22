#include <stdio.h>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <functional>
#include <iostream>
#include <climits>
#include <stdlib.h>
#include <cstring>
#include <cmath>
#include <utility>
#include <deque>

using namespace std;

int N, M;
vector<int> require;

inline int cando(int maxmoney) {
  int total = 0;
  int givemax = -1;
  for(int i=0; i<N; i++) {
    int give = min(require[i], maxmoney);
    givemax = max(givemax, give);
    total += give;
  }
  if(total <= M) return givemax;
  return -1;
}

int search(int lo, int hi) {
  if(lo == hi) return lo;
  int mid = (lo+hi)/2+1;
  if(cando(mid) > 0) return search(mid,hi);
  return search(lo,mid-1);
}

int main() {
  scanf("%d", &N);
  require.resize(N);
  for(int i=0; i<N; i++) scanf("%d", &require[i]);
  scanf("%d", &M);
  printf("%d\n", cando(search(1,100000)));
}