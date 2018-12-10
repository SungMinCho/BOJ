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

#define MAXN 32001
#define MAXM 100001

int N, M;

vector<vector<int>> adj;
vector<int> order;
vector<bool> viz;

void dfs(int here) {
  viz[here] = true;
  for(auto there : adj[here]) {
    if(!viz[there]) dfs(there);
  }
  order.push_back(here);
}

int main() {
  scanf("%d %d", &N, &M);
  adj.resize(N+1);
  for(int i=0; i<M; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    adj[a].push_back(b);
  }

  viz.resize(N+1, false);
  for(int i=1; i<=N; i++) if(!viz[i]) dfs(i);
  
  reverse(order.begin(), order.end());
  for(auto o : order) cout << o << ' ';
  cout << endl;
}
