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

using namespace std;
typedef long long ll;

int T, N, M;
vector<vector<int>> adj;
bool viz[1001];
int parent[1001];
bool cycle;

void dfs(int here) {
  viz[here] = true;
  for(auto& there : adj[here]) {
    if(!viz[there]) {
      parent[there] = here;
      dfs(there);
    } else if(there != parent[here]) {
      cycle = true;
    }
  }
}

int main() {
  scanf("%d", &T);
  for(int t=0; t<T; t++) {
    scanf("%d %d", &N, &M);
    adj.clear(); adj.resize(N+1);
    for(int i=0; i<M; i++) {
      int a, b; scanf("%d %d", &a, &b);
      adj[a].push_back(b);
      adj[b].push_back(a);
    }

    memset(viz,0,sizeof(viz));
    memset(parent,0,sizeof(parent));
    cycle = false;
    dfs(1);
    bool allviz = true;
    for(int i=1; i<=N; i++) {
      if(!viz[i]) {
        allviz = false;
        break;
      }
    }

    if(!allviz || cycle) {
      printf("graph\n");
    } else printf("tree\n");
  }
}