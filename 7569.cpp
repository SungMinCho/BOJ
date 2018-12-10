#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

#define MAXN 105

struct Tomato {
  int x, y, z;
};

int tomato[MAXN][MAXN][MAXN];
int n, m, h;
int offset[6][3] = {{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};

int main() {
  vector<Tomato> qt;
  int zerocount = 0;

  scanf("%d %d %d", &m, &n, &h);
  for(int z=1; z<=h; z++) {
    for(int i=1; i<=n; i++) {
      for(int j=1; j<=m; j++){
        scanf("%d", &tomato[z][i][j]);

        if(tomato[z][i][j] == 1) {
          qt.push_back({.x = i, .y = j, .z = z});
        }
        else if(tomato[z][i][j] == 0) zerocount++;
      }
    }
  }

  int cnt = 0;
  while(!qt.empty()) {
    vector<Tomato> qq;
    for(auto t : qt) {
      for(int o = 0 ; o < 6; o++) {
        int xx = t.x + offset[o][1];
        int yy = t.y + offset[o][2];
        int zz = t.z + offset[o][0];
        if(xx < 1 || xx > n || yy < 1 || yy > m || zz < 1 || zz > h) continue;
        if(tomato[zz][xx][yy] == 0) {
          tomato[zz][xx][yy] = 1;
          zerocount--;
          qq.push_back({.x = xx, .y = yy, .z = zz});
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
