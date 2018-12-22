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

struct State {
  int x, y, brokeWall, dist;
  State(int x_, int y_, int b, int d) : x(x_),y(y_),brokeWall(b),dist(d) {}
};

int N,M;
string board[1000];
bool viz[1000][1000][2];
queue<State> q;
int offset[4][2] = {
  {0,1},{0,-1},{1,0},{-1,0}
};

void insert(State s) {
  if(viz[s.x][s.y][s.brokeWall]) return;
  viz[s.x][s.y][s.brokeWall] = true;
  q.push(s);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N >> M;
  string s;
  getline(cin, s);
  for(int i=0; i<N; i++) getline(cin, board[i]);
  insert(State(0,0,0,0));
  bool done = false;
  while(!q.empty()) {
    State t = q.front(); q.pop();
    for(int o=0; o<4; o++) {
      int x = t.x+offset[o][0];
      int y = t.y+offset[o][1];
      if(x < 0 || x >= N || y < 0 || y >= M) continue;
      if(board[x][y] == '1') {
        if(t.brokeWall == 0) {
          insert(State(x,y,1,t.dist+1));
        }
      } else {
        insert(State(x,y,t.brokeWall,t.dist+1));
      }
    }

    if(t.x == N-1 && t.y == M-1) {
      done = true;
      cout << t.dist+1 << '\n';
      break;
    }
  }
  if(!done) cout << -1 << '\n';
}