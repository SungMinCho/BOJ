#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

#define MAXN 2002
#define min(a,b) (a<b?a:b)

int N, M;

bool viz[MAXN][MAXN];
char board[MAXN][MAXN];
int nodes[MAXN][MAXN];
int nodenum = 0;
int offset[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

map<int,bool> isIsland;

map<int, map<int,bool>> adjMap;
vector<int> parent;
vector<int> low;
vector<int> discover;
vector<int> mark;
int timecnt;

void fill(int i, int j, char val) {
  if(viz[i][j] || board[i][j] != val) return;
  viz[i][j] = true;
  nodes[i][j] = nodenum;
  for(int k=0; k<4; k++) fill(i+offset[k][0], j+offset[k][1], val);
}

void makeNodes() {
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=M; j++) {
      if(!viz[i][j]) {
        nodenum++;
        isIsland[nodenum] = (board[i][j] == '#');
        fill(i, j, board[i][j]);
      }
    }
  }
}

void makeAdj() {
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=M; j++) {
      int node1 = nodes[i][j];
      for(int k=0; k<4; k++) {
        int node2 = nodes[i+offset[k][0]][j+offset[k][1]];
        if(node1 != node2) {
          adjMap[node1][node2] = true;
          adjMap[node2][node1] = true;
        }
      }
    }
  }
}

void markDead(int fromtime, int totime) {
  mark[fromtime] += 1;
  mark[totime+1] -= 1;
}

void dfs(int node, bool isRoot) {
  timecnt++;
  discover[node] = timecnt;
  low[node] = timecnt;
  for(auto akv : adjMap[node]) {
    auto a = akv.first;
    if(discover[a] == 0) { // not visited
      parent[a] = node;
      dfs(a, false);
      low[node] = min(low[node], low[a]);
      if(!isRoot && low[a] >= discover[node] && isIsland[node]) {
        // articulation point (only when is Island)
        // mark all nodes in the dependent subtree as dead
        // discover : discover[node] ~ current timecnt = whole subtree
        markDead(discover[a], timecnt);
      }
    } else if(a != parent[node]) {
      low[node] = min(low[node], discover[a]);
    }
  }
}

void calculateMarks() {
  for(int i=2; i<=nodenum; i++) mark[i] += mark[i-1];
}

int main() {
  scanf("%d %d", &N, &M);
  for(int i=1; i<=N; i++) scanf("%s", board[i]+1);
  // borders
  for(int i=0; i<=N+1; i++) viz[i][0] = viz[i][M+1] = true;
  for(int j=0; j<=M+1; j++) viz[0][j] = viz[N+1][j] = true;
  for(int i=0; i<=N+1; i++) nodes[i][0] = nodes[i][M+1] = 1;
  for(int j=0; j<=M+1; j++) nodes[0][j] = nodes[N+1][j] = 1;

  makeNodes();
  makeAdj();
  parent.resize(nodenum+1);
  low.resize(nodenum+1);
  discover.resize(nodenum+1, 0);
  mark.resize(nodenum+2, 0);
  timecnt = 0;
  dfs(1, true);

  calculateMarks();

  for(int i=1; i<=N; i++) {
    for(int j=1; j<=M; j++) {
      int node = nodes[i][j];
      if(!isIsland[node]) cout << '.';
      else if(mark[discover[node]] > 0) cout << 'X';
      else cout << 'O';
    }
    cout << endl;
  }
}
