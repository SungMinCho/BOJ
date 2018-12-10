#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

#define MAXN 105

struct Pos{
  int x, y;
};

int board[MAXN][MAXN];
int n, m, h;
int offset[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

int main() {
  vector<Pos> qt;
  qt.push_back({.x = 1, .y = 1});

  scanf("%d %d", &n, &m);
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=m; j++){
      char c;
      cin >> c;
      board[i][j] = (c =='0' ? 0 : 1);
    }
  }

  board[1][1] = 2; // visited

  int cnt = 0;
  while(!qt.empty()) {
    cnt += 1;
    vector<Pos> qq;
    for(auto t : qt) {
      for(int o = 0 ; o < 4; o++) {
        int xx = t.x + offset[o][0];
        int yy = t.y + offset[o][1];
        if(xx < 1 || xx > n || yy < 1 || yy > m) continue;
        if(board[xx][yy] == 1) {
          board[xx][yy] = 2;
          qq.push_back({.x = xx, .y = yy});
        }
      }
    }

    if(board[n][m] == 2) break;
    qt = qq;
  }

  cout << cnt+1 << endl;

  return 0;
}
