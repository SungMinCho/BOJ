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

int N, C;
vector<int> pos;

inline int cando(int maxdist) {
  int cnt = 1;
  int last = pos[0];
  int i = 1;
  int actualmaxdist = 987654321;
  while(i<N) {
    while(i<N && pos[i]-last < maxdist) i++;
    if(i==N) break;
    cnt++;
    actualmaxdist = min(actualmaxdist, pos[i]-last);
    last = pos[i];
  }
  if(cnt >= C) return actualmaxdist;
  return -1;
}

int search(int lo, int hi) {
  if(lo == hi) return lo;
  int mid = (lo+hi)/2+1;
  if(cando(mid) > 0) return search(mid,hi);
  return search(lo,mid-1);
}

int main() {
  scanf("%d %d", &N, &C);
  pos.resize(N);
  for(int i=0; i<N; i++) scanf("%d", &pos[i]);
  sort(pos.begin(), pos.end());
  printf("%d\n", cando(search(1, 1000000000)));
}