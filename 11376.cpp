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

int N, M, src, tgt;
int cap[2004][2004];
int flow[2004][2004];
vector<vector<int>> adj;

int ff() {
  int totalFlow = 0;
  while(true) {
    int parent[N+M+3];
    memset(parent, -1, sizeof(parent));
    queue<int> q;
    q.push(src);
    parent[src] = src;
    while(!q.empty() && parent[tgt] == -1) {
      int t = q.front(); q.pop();
      for(auto there : adj[t]) {
        if(cap[t][there]-flow[t][there] > 0 && parent[there] == -1) {
          parent[there] = t;
          q.push(there);
        }
      }
    }
    if(parent[tgt] == -1) break;
    int amount = 987654321;
    for(int t=tgt; t!=src; t=parent[t]) {
      amount = min(amount, cap[parent[t]][t] - flow[parent[t]][t]);
    }
    for(int t=tgt; t!=src; t=parent[t]) {
      flow[parent[t]][t] += amount;
      flow[t][parent[t]] -= amount;
    }
    totalFlow += amount;
  }

  return totalFlow;
}

void addEdge(int from, int to, int c) {
  cap[from][to] = c;
  adj[from].push_back(to);
  adj[to].push_back(from);
}

int main() {
  scanf("%d %d", &N, &M);
  src = 0; tgt = N+M+1;
  adj.resize(tgt+1);
  for(int i=1; i<=N; i++) addEdge(src,i,2);
  for(int i=1; i<=N; i++) {
    int a; scanf("%d", &a);
    for(int j=1; j<=a; j++) {
      int w; scanf("%d", &w);
      addEdge(i,N+w,1);
    }
  }
  for(int i=1; i<=M; i++) addEdge(N+i,tgt,1);

  printf("%d\n", ff());
}