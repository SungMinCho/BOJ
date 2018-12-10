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

int N, M;
vector<vector<int>> adj;
vector<int> indegree;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
  scanf("%d %d", &N, &M);
  adj.resize(N+1);
  indegree.resize(N+1, 0);
  for(int i=0; i<M; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    adj[a].push_back(b);
    indegree[b]++;
  }

  vector<int> ans;

  for(int i=1; i<=N; i++) if(indegree[i] == 0) pq.push(i);

  while(!pq.empty()) {
    int t = pq.top(); pq.pop();
    ans.push_back(t);
    for(auto d : adj[t]) {
      indegree[d]--;
      if(indegree[d] == 0) pq.push(d);
    }
  }

  for(auto a : ans) cout << a << ' ';
  cout << endl;
}
