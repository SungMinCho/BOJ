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

int T, N, M;
int adj[101][101];
int receiveAt[101];
vector<bool> viz;

bool match(int here) {
  for(int there=1; there<=N; there++) {
    if(adj[here][there] && !viz[there]) {
      viz[there] = true;
      if(receiveAt[there] == -1 || match(receiveAt[there])) {
        receiveAt[there] = here;
        return true;
      }
    }
  }
  return false;
}

int leastTime() {
  int total=0;
  for(int t=0; t<=99; t++) {
    viz.clear();
    viz.resize(N+1, false);
    if(match(t)) total++;
    if(total == N) return t+1;
  }
  return -1;
}

int main() {
  scanf("%d", &T);
  for(int t=0; t<T; t++) {
    for(int i=0; i<=100; i++) for(int j=1; j<=100; j++) adj[i][j] = 0;
    for(int j=1; j<=100; j++) receiveAt[j] = -1;

    scanf("%d %d", &N, &M);
    for(int i=1; i<=M; i++) {
      int t1, t2, a; scanf("%d %d %d", &t1, &t2, &a);
      for(int j=1; j<=a; j++) {
        int q; scanf("%d", &q);
        for(int ti=t1; ti<t2; ti++) adj[ti][q] = 1;
      }
    }

    printf("%d\n", leastTime());
  }
}