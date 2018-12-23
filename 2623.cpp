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
#include <assert.h>

using namespace std;

int N, M;
int buffer[1001];
bool adj[1001][1001];
vector<int> discovered;
vector<bool> finished;
int discovertime;
bool cycle;
vector<int> ans;

void dfs(int here) {
  discovered[here] = ++discovertime;
  for(int there=1; there<=N; there++) {
    if(!adj[here][there]) continue;
    if(discovered[there] == -1) dfs(there);
    else if(discovered[there] < discovered[here]) {
      if(!finished[there]) {
        cycle = true;
        return;
      }
    }
  }
  finished[here] = true;
  ans.push_back(here);
}

int main() {
  scanf("%d %d", &N, &M);
  for(int i=1; i<=M; i++) {
    int k; scanf("%d", &k);
    for(int j=1; j<=k; j++) scanf("%d", &buffer[j]);
    for(int j=1; j<k; j++) for(int jj=j+1; jj<=k; jj++) adj[buffer[j]][buffer[jj]] = true;
  }

  discovered.resize(N+1, -1);
  finished.resize(N+1, false);
  for(int i=1; i<=N; i++) {
    if(discovered[i] == -1) dfs(i);
    if(cycle) break;
  }
  if(cycle) printf("0\n");
  else for(int i=N-1; i>=0; i--) printf("%d\n", ans[i]);
}