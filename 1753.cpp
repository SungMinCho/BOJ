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

struct VD {
  int V, D;
};

struct comp {
  inline bool operator()(const VD& a, const VD& b) { return a.D > b.D; }
};

int V, E, start;
vector<vector<VD>> adj;
vector<int> mindist;
vector<bool> done;
priority_queue<VD, vector<VD>, comp> pq;

int main() {
  scanf("%d %d %d", &V, &E, &start);
  adj.resize(V+1);
  mindist.resize(V+1, INT_MAX);
  done.resize(V+1);
  for(int e=0; e<E; e++) {
    int a, b, w;
    scanf("%d %d %d", &a, &b, &w);
    adj[a].push_back({.V=b,.D=w});
  }

  pq.push({.V=start, .D=0});
  mindist[start] = 0;
  while(!pq.empty()) {
    VD t = pq.top(); pq.pop();
    if(done[t.V]) continue;
    done[t.V] = true;

    for(auto edge : adj[t.V]) {
      int v = edge.V;
      int d = edge.D;
      if(!done[v] && mindist[t.V] + d < mindist[v]) {
        mindist[v] = mindist[t.V] + d;
        pq.push({.V=v, .D=mindist[v]});
      }
    }
  }

  for(int i=1; i<=V; i++) {
    if(mindist[i] == INT_MAX) cout << "INF" << endl;
    else cout << mindist[i] << endl;
  }
}
