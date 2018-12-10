#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

#define MAXN 100005

int n;
vector<vector<int>> adj;
vector<int> parent;

void teachParent(int at, int par) {
  parent[at] = par;

  for(auto c : adj[at]) {
    if(parent[c] == 0 && c != 1) {
      teachParent(c, at);
    }
  }
}

int main() {
  scanf("%d", &n);
  adj.resize(n+1);
  parent.resize(n+1);

  for(int i=0; i<n-1; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  teachParent(1, 0);

  for(int i=2; i<=n; i++) printf("%d\n", parent[i]);
}
