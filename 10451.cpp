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

int T, N;
vector<vector<int>> adj;
vector<int> discovered;
int cnt;
int timeCnt;

void dfs(int here) {
  discovered[here] = ++timeCnt;
  for(auto there : adj[here]) {
    if(discovered[there] == -1) dfs(there);
    else if(discovered[there] <= discovered[here]) cnt++;
  }
}

int main() {
  scanf("%d", &T);

  for(int t=0; t<T; t++) {
    scanf("%d", &N);
    adj.clear();
    adj.resize(N+1);
    for(int i=1; i<=N; i++) {
      int a;
      scanf("%d", &a);
      adj[i].push_back(a);
    }

    discovered.clear();
    discovered.resize(N+1, -1);
    cnt = 0;
    timeCnt = 0;
    for(int i=1; i<=N; i++) if(discovered[i] == -1) dfs(i);
    printf("%d\n", cnt);
  }
}
