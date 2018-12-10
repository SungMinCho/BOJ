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

void calcMinDistFromTo(int start, int end) {
  mindist.clear();
  mindist.resize(V+1, INT_MAX);
  done.clear();
  done.resize(V+1, false);
  pq = priority_queue<VD, vector<VD>, comp>();
  pq.push({.V=start, .D=0});
  mindist[start] = 0;
  while(!pq.empty()) {
    VD t = pq.top(); pq.pop();
    if(done[t.V]) continue;
    done[t.V] = true;
    if(t.V == end) break;

    for(auto edge : adj[t.V]) {
      int v = edge.V;
      int d = edge.D;
      if(!done[v] && mindist[t.V] + d < mindist[v]) {
        mindist[v] = mindist[t.V] + d;
        pq.push({.V=v, .D=mindist[v]});
      }
    }
  }
}

int main() {
  scanf("%d %d", &V, &E);
  adj.resize(V+1);
  for(int e=0; e<E; e++) {
    int a, b, w;
    scanf("%d %d %d", &a, &b, &w);
    adj[a].push_back({.V=b,.D=w});
    adj[b].push_back({.V=a,.D=w});
  }

  int mid1, mid2;
  scanf("%d %d", &mid1, &mid2);

  int ans1 = 0;
  bool noroute1 = false;
  calcMinDistFromTo(1, mid1);
  ans1 += mindist[mid1];
  if(mindist[mid1] == INT_MAX) noroute1 = true;
  calcMinDistFromTo(mid1, mid2);
  ans1 += mindist[mid2];
  if(mindist[mid2] == INT_MAX) noroute1 = true;
  calcMinDistFromTo(mid2, V);
  ans1 += mindist[V];
  if(mindist[V] == INT_MAX) noroute1 = true;

  int ans2 = 0;
  bool noroute2 = false;
  calcMinDistFromTo(1, mid2);
  ans2 += mindist[mid2];
  if(mindist[mid2] == INT_MAX) noroute2 = true;
  calcMinDistFromTo(mid2, mid1);
  ans2 += mindist[mid1];
  if(mindist[mid1] == INT_MAX) noroute2 = true;
  calcMinDistFromTo(mid1, V);
  ans2 += mindist[V];
  if(mindist[V] == INT_MAX) noroute2 = true;

  if(noroute1 && noroute2) cout << -1 << endl;
  else cout << (ans1 < ans2 ? ans1 : ans2) << endl;
}
