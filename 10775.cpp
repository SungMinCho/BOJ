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

int G, P;
int g[100001];

struct DS {
  vector<int> parent;
  DS(int n) : parent(n) {
    for(int i=0; i<n; i++) parent[i] = i ;
  }

  int root(int x) {
    if(x==parent[x]) return x;
    return parent[x] = root(parent[x]);
  }

  void merge(int a, int b) {
    int ra = root(a); int rb = root(b);
    if(rb>ra) swap(rb,ra);
    if(ra!=rb) parent[ra]=rb;
  }
};

int main() {
  scanf("%d %d", &G, &P);
  DS ds(G+1);
  for(int i=1; i<=P; i++) scanf("%d", &g[i]);
  int cnt = 0;
  for(int i=1; i<=P; i++) {
    int r = ds.root(g[i]);
    if(r==0) break;
    cnt++;
    ds.merge(r-1,r);
  }
  printf("%d\n", cnt);
}