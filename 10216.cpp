#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

struct Pos {
  int x, y, r;
};

#define MAXN 3005
int T, N;
vector<Pos> ps;
vector<vector<int>> adj;
vector<bool> viz;

bool overlap(Pos& a, Pos& b) {
  int centerdist = (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
  if((a.r+b.r)*(a.r+b.r) >= centerdist) return true;
  return false;
}

void fill(int i) {
  if(viz[i]) return;
  viz[i] = true;
  for(auto a : adj[i]) fill(a);
}

int main() {
  scanf("%d", &T);
  for(int t=0; t<T; t++) {
    scanf("%d", &N);
    ps.clear();
    ps.resize(N);
    adj.clear();
    adj.resize(N);
    viz.clear();
    viz.resize(N, false);
    for(int i=0; i<N; i++) {
      int x, y, r;
      scanf("%d %d %d", &x, &y, &r);
      ps[i] = {.x=x,.y=y,.r=r};
    }
    for(int i=0; i<N-1; i++) {
      for(int j=i+1; j<N; j++) {
        if(overlap(ps[i], ps[j])) {
          adj[i].push_back(j);
          adj[j].push_back(i);
        }
      }
    }

    int cnt = 0;
    for(int i=0; i<N; i++) {
      if(!viz[i]) {
        cnt++;
        fill(i);
      }
    }

    cout << cnt << endl;
  }
}
