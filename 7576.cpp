#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

#define MAXN 1005

struct Tomato {
  int x, y;
};

int tomato[MAXN][MAXN];
int n, m;
int offset[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

bool next2one(int i, int j) {
  for(int o=0; o<4; o++) {
    int ii = i + offset[o][0];
    int jj = j + offset[o][1];
    if(ii < 1 || ii > n || jj < 1 || jj > m) continue;
    if(tomato[ii][jj] == 1) return true;
  }
  return false;
}

int main() {
  vector<Tomato> qt;
  int zerocount = 0;

  scanf("%d %d", &m, &n);
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=m; j++){
      scanf("%d", &tomato[i][j]);

      if(tomato[i][j] == 1) {
        qt.push_back({.x = i, .y = j});
      }
      else if(tomato[i][j] == 0) zerocount++;
    }
  }

  int cnt = 0;
  while(!qt.empty()) {
    vector<Tomato> qq;
    for(auto t : qt) {
      for(int o = 0 ; o < 4; o++) {
        int xx = t.x + offset[o][0];
        int yy = t.y + offset[o][1];
        if(xx < 1 || xx > n || yy < 1 || yy > m) continue;
        if(tomato[xx][yy] == 0) {
          tomato[xx][yy] = 1;
          zerocount--;
          qq.push_back({.x = xx, .y = yy});
        }
      }
    }

    if(!qq.empty()) cnt++;
    qt = qq;
  }

  if(zerocount > 0) cout << -1 << endl;
  else cout << cnt << endl;

  return 0;
}
