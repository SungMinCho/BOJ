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
  T = 1;
  for(int t=0; t<T; t++) {
    scanf("%d %d", &N, &M);
    vector<Edge> edges;
    vector<vector<bool>> reachable(N+1, vector<bool>(N+1,false));
    for(int i=1; i<=N; i++) reachable[i][i] = true;
    for(int i=0; i<M; i++) {
      int a, b, t;
      scanf("%d %d %d", &a, &b, &t);
      edges.push_back({.a=a,.b=b,.t=t});
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
      }
    }

    bool cycle = false;
    for(auto edge : edges) {
      int a = edge.a;
      int b = edge.b;
      int t = edge.t;
      if(upper[a] != INT_MAX && upper[a]+t < upper[b] &&
          reachable[1][a]) cycle = true;
    }

    if(cycle) cout << -1 << endl;
    else {
      for(int i=2; i<=N; i++) {
        if(upper[i] == INT_MAX) cout << -1 << endl;
        else cout << upper[i] << endl;
      }
    }
  }
}
