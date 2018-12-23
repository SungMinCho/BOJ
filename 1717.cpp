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
#include <assert.h>

using namespace std;

int N, M;

struct DS {
  vector<int> parent;
  DS(int n) {
    parent.resize(n);
    for(int i=0; i<n; i++) parent[i] = i;
  }

  int root(int a) {
    if(parent[a] == a) return a;
    return parent[a] = root(parent[a]);
  }

  void merge(int a, int b) {
    int ra = root(a);
    int rb = root(b);
    if(ra!=rb) parent[ra]=rb;
  }
};

int main() {
  scanf("%d %d", &N, &M);
  N++;
  DS ds(N);
  for(int i=0; i<M; i++) {
    int cmd, a, b;
    scanf("%d %d %d", &cmd, &a, &b);
    if(cmd==0) ds.merge(a,b);
    else {
      int ra = ds.root(a); int rb = ds.root(b);
      if(ra==rb) printf("YES\n");
      else printf("NO\n");
    }
  }
}