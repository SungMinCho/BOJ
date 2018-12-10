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

#define MAXN 501
#define MAXM 25001

vector<int> origPlace;
vector<int> origOrder;

int T, N, M;

bool adj[MAXN][MAXN];
bool cycle;
vector<int> order;
vector<bool> viz;
vector<bool> done;

void dfs(int here) {
  viz[here] = true;
  for(int there=1; there<=N && !cycle; there++) {
    if(adj[here][there]) {
      if(viz[there] && !done[there]) {
        cycle = true;
        return;
      }
      else if(!viz[there]) dfs(there);
    }
  }
  order.push_back(here);
  done[here] = true;
}

int main() {
  scanf("%d", &T);
  for(int t=0; t<T; t++) {
    scanf("%d", &N);
    origPlace.clear();
    origPlace.resize(N+1);
    origOrder.resize(0);
    for(int i=1; i<=N; i++) {
      int a;
      scanf("%d", &a);
      origPlace[a] = i;
      origOrder.push_back(a);
    }

    fill(&adj[0][0], &adj[0][0]+sizeof(adj), false);
    for(int i=0; i<N-1; i++) {
      for(int j=i+1; j<N; j++) {
        adj[origOrder[i]][origOrder[j]] = true;
      }
    }
    
    scanf("%d", &M);
    for(int i=0; i<M; i++) {
      int a, b;
      scanf("%d %d", &a, &b);
      if(adj[a][b]) swap(a,b);
      adj[a][b] = true;
      adj[b][a] = false;
    }

    cycle = false;
    order.clear();
    viz.clear();
    viz.resize(N+1, false);
    done.clear();
    done.resize(N+1, false);
    for(int i=1; i<=N && !cycle; i++) if(!viz[i]) dfs(i);
    
    if(cycle) cout << "IMPOSSIBLE" << endl;
    else {
      reverse(order.begin(), order.end());
      for(auto o : order) cout << o << ' ';
      cout << endl;
    }
  }
}
