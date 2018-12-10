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

struct Travel {
  int dest, dist, money;
};

struct ByDist {
  inline bool operator()(const Travel& a, const Travel& b) { return a.dist > b.dist; }
};


int T, N, MaxCost, K;
priority_queue<Travel, vector<Travel>, ByDist>* pq;
vector<vector<Travel>> adj;
vector<vector<int>> dist;

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

int main() {
  pq = new priority_queue<Travel, vector<Travel>, ByDist>();
  scanf("%d", &T);
  for(int t=0; t<T; t++) {
    scanf("%d %d %d", &N, &MaxCost, &K);
    adj.clear();
    adj.resize(N+1);
    dist.clear();
    dist.resize(N+1, vector<int>(MaxCost+1, INT_MAX));
    for(int i=0; i<K; i++) {
      int u, v, c, d;
      scanf("%d %d %d %d", &u, &v, &c, &d);
      adj[u].push_back({.dest=v, .dist=d, .money=c});
    }

    delete pq;
    pq = new priority_queue<Travel, vector<Travel>, ByDist>();
    pq->push({.dest=1, .dist=0, .money=0});
    dist[1][0] = 0;

    while(!pq->empty()) {
      auto top = pq->top(); pq->pop();
      int at = top.dest;
      if(top.dist > dist[at][top.money]) continue;
      for(auto e : adj[at]) {
        if(top.money + e.money > MaxCost) continue;
        if(top.dist + e.dist >= dist[e.dest][top.money+e.money]) continue;
        dist[e.dest][top.money+e.money] = top.dist+e.dist;
        pq->push({.dest=e.dest, .dist=top.dist+e.dist, .money=top.money+e.money});
      }
    }

    int ans = INT_MAX;
    for(int money = 0; money <= MaxCost; money++) ans = min(ans, dist[N][money]);

    if(ans == INT_MAX) cout << "Poor KCM" << endl;
    else cout << ans << endl;
  }
}
