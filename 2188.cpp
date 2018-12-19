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

int adj[201][201];
bool viz[201];
int haveCow[201];
int N, M;

bool match(int here) {
  for(int there=1; there<=M; there++) {
    if(adj[here][there] && !viz[there]) {
      viz[there] = true;
      if(!haveCow[there] || match(haveCow[there])) {
        haveCow[there] = here;
        return true;
      }
    }
  }
  return false;
}

int maxmatch() {
  int total = 0;
  for(int cow=1; cow<=N; cow++) {
    for(int i=1; i<=M; i++) viz[i] = false;
    if(match(cow)) total++;
  }

  return total;
}

int main() {
  scanf("%d %d", &N, &M);
  for(int i=1; i<=N; i++) {
    int s; scanf("%d", &s);
    for(int j=1; j<=s; j++) {
      int w; scanf("%d", &w);
      adj[i][w] = 1;
    }
  }

  printf("%d\n", maxmatch());
}