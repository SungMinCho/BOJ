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

using namespace std;

int N, M;
int adj[1001][1001];
int worker[1001];
vector<bool> viz;

bool match(int here) {
  for(int there=1; there<=M; there++) {
    if(adj[here][there] && !viz[there]) {
      viz[there] = true;
      if(!worker[there] || match(worker[there])) {
        worker[there] = here;
        return true;
      }
    }
  }
  return false;
}

int maxmatch() {
  int total = 0;
  for(int i=1; i<=N; i++) {
    viz.clear(); viz.resize(N+1, false);
    if(match(i)) total++;
  }
  return total;
}

int main() {
  scanf("%d %d", &N, &M);
  for(int i=1; i<=N; i++) {
    int a; scanf("%d", &a);
    for(int j=1; j<=a; j++) {
      int w; scanf("%d", &w);
      adj[i][w] = 1;
    }
  }

  printf("%d\n", maxmatch());
}