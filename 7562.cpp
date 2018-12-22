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

using namespace std;

struct Piece {
  int row, col;
  Piece(int r, int c) : row(r), col(c) {}
  inline bool operator==(const Piece& other) {
    return row == other.row && col == other.col;
  }
  inline bool operator<(const Piece& other) const {
    if(row==other.row) return col < other.col;
    return row < other.row;
  }
};

int T, L;
int viz[300][300];
int offset[8][2] = {
  {1,-2},
  {2,-1},
  {1,2},
  {2,1},
  {-2,-1},
  {-1,-2},
  {-2,1},
  {-1,2},
};

int main() {
  scanf("%d", &T);
  for(int t=0; t<T; t++) {
    scanf("%d", &L);
    memset(viz, -1, sizeof(viz));
    int x, y;
    scanf("%d %d", &x, &y);
    Piece start(x,y);
    scanf("%d %d", &x, &y);
    Piece end(x,y);
    if(start == end) {
      printf("0\n"); continue;
    }

    queue<Piece> q;
    q.push(start);
    viz[start.row][start.col] = 0;
    while(!q.empty()) {
      auto top = q.front(); q.pop();
      int cnt = viz[top.row][top.col];
      for(int o=0; o<8; o++) {
        int row = top.row+offset[o][0];
        int col = top.col+offset[o][1];
        if(row < 0 || row >= L || col < 0 || col >= L) continue;
        Piece next(row,col);
        if(viz[next.row][next.col] != -1) continue;
        viz[next.row][next.col] = cnt+1;
        q.push(next);
        if(next == end) {
          printf("%d\n", cnt+1);
          break;
        }
      }
    }
  }
}