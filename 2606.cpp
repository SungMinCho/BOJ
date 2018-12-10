#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

int n, m;
vector<vector<int>> adj;
vector<bool> viz;

int main() {
  cin >> n >> m;
  adj.resize(n+1);
  viz.resize(n+1);
  for(int i=1; i<=m; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  int cnt = 0;
  viz[1] = true;
  queue<int> q;
  q.push(1);
  while(!q.empty()) {
    int t = q.front();
    q.pop();
    for(auto b : adj[t]) {
      if(!viz[b]) {
        viz[b] = true;
        cnt++;
        q.push(b);
      }
    }
  }

  cout << cnt << endl;

  return 0;
}
