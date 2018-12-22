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

typedef long long ll;

int N;
ll M;
ll tree[1000000];

inline ll get(int cutHeight, int treei) {
  return max((ll)0, tree[treei] - cutHeight);
}

inline bool canGet(int cutHeight) {
  ll total = 0;
  for(int i=0; i<N; i++) {
    total += get(cutHeight, i);
    if(total >= M) return true;
  }
  return false;
}

int search(int lo, int hi) {
  if(lo == hi) return lo;
  int mid = (lo+hi)/2+1;
  if(canGet(mid)) return search(mid, hi);
  return search(lo, mid-1);
}

int main() {
  scanf("%d %lld", &N, &M);
  for(int i=0; i<N; i++) scanf("%lld", &tree[i]);
  printf("%d\n", search(0, 1000000000));
}