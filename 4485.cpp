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

int board[125][125];
int mindist[125][125];
int N;
int problem;

struct Pos {
  int row, col, dist;
  Pos(int r, int c, int d) : row(r), col(c), dist(d) {}
};

struct Comp {
  inline bool operator()(const Pos& a, const Pos& b) {
    if(a.dist == b.dist) return a.row > b.row || a.col > b.col;
    return a.dist > b.dist;
  }
};

int offset[4][2] = {
  {0,1},{0,-1},{1,0},{-1,0}
};

priority_queue<Pos, vector<Pos>, Comp> pq;

int main() {
  while(true) {
    problem++;
    scanf("%d", &N);
    if(N==0) break;
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) scanf("%d", &board[i][j]);
    memset(mindist, -1, sizeof(mindist));
    pq.push(Pos(0,0,board[0][0]));
    mindist[0][0] = board[0][0];
    while(!pq.empty()) {
      auto t = pq.top(); pq.pop();
      if(t.dist > mindist[t.row][t.col]) continue;
      for(int o=0; o<4; o++) {
        int r = t.row + offset[o][0];
        int c = t.col + offset[o][1];
        if(r < 0 || r >= N || c < 0 || c >= N) continue;
        int d = t.dist + board[r][c];
        if(mindist[r][c] != -1 && mindist[r][c] <= d) continue;
        mindist[r][c] = d;
        pq.push(Pos(r,c,d));
      }
    }


    printf("Problem %d: %d\n", problem, mindist[N-1][N-1]);
  }
}