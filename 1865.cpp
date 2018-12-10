#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

#define MAXV 20001
#define MAXE 300001

struct Edge {
  int a, b, t;
};

int T, N, M, W;

int main() {
  scanf("%d", &T);
  for(int t=0; t<T; t++) {
    scanf("%d %d %d", &N, &M, &W);
    vector<Edge> edges;
    vector<Edge> wormholes;
    vector<vector<bool>> reachable(N+1, vector<bool>(N+1,false));
    for(int i=1; i<=N; i++) reachable[i][i] = true;
    for(int i=0; i<M; i++) {
      int a, b, t;
      scanf("%d %d %d", &a, &b, &t);
      edges.push_back({.a=a,.b=b,.t=t});
      reachable[a][b] = reachable[b][a] = true;
    }
    for(int i=0; i<W; i++) {
      int a, b, t;
      scanf("%d %d %d", &a, &b, &t);
      wormholes.push_back({.a=a,.b=b,.t=-t});
      reachable[a][b] = true;
    }
    for(int k=1; k<=N; k++) {
      for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
          reachable[i][j] = reachable[i][j] || (reachable[i][k] && reachable[k][j]);
        }
      }
    }

    vector<int> upper(N+1, INT_MAX);
    upper[1] = 0;
    for(int k=0; k<N-1; k++) {
      for(auto edge : edges) {
        int a = edge.a;
        int b = edge.b;
        int t = edge.t;
        if(upper[a] != INT_MAX && upper[a]+t < upper[b]) upper[b] = upper[a]+t;
        if(upper[b] != INT_MAX && upper[b]+t < upper[a]) upper[a] = upper[b]+t;
      }
      for(auto wormhole : wormholes) {
        int a = wormhole.a;
        int b = wormhole.b;
        int t = wormhole.t;
        if(upper[a] != INT_MAX && upper[a]+t < upper[b]) upper[b] = upper[a]+t;
      }
    }

    bool cycle = false;
    for(auto edge : edges) {
      int a = edge.a;
      int b = edge.b;
      int t = edge.t;
      if(upper[a] != INT_MAX && upper[a]+t < upper[b] &&
          reachable[1][a] && reachable[a][1]) cycle = true;
      if(upper[b] != INT_MAX && upper[b]+t < upper[a] &&
          reachable[1][b] && reachable[b][1]) cycle = true;
    }
    for(auto wormhole : wormholes) {
      int a = wormhole.a;
      int b = wormhole.b;
      int t = wormhole.t;
      if(upper[a] != INT_MAX && upper[a]+t < upper[b] &&
          reachable[1][a] && reachable[a][1]) cycle = true;
    }

    if(upper[1] < 0 || cycle) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}
