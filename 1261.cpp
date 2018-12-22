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

struct Pos {
  int row, col;
  Pos(int r, int c) : row(r), col(c) {}
};

string board[101];
bool viz[101][101][2];
int N, M, ans;
int vizat;

int offset[4][2] = {
  {0,1},{0,-1},{1,0},{-1,0}
};

void fillzero(int i, int j) {
  for(int o=0; o<4; o++) {
    int ii = i + offset[o][0];
    int jj = j + offset[o][1];
    if(ii < 1 || ii > N || jj < 1 || jj > M) continue;
    if(board[ii][jj] == '0' && !viz[ii][jj][vizat]) {
      viz[ii][jj][vizat] = true;
      fillzero(ii,jj);
    }
  }
}

void fillzero() {
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=M; j++) {
      if(board[i][j] == '0' && viz[i][j][vizat]) fillzero(i,j);
    }
  }
}

void breakwalls() {
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=M; j++) {
      viz[i][j][1-vizat] = viz[i][j][vizat];
      if(viz[i][j][1-vizat]) continue;

      if(board[i][j] == '1') {
        for(int o=0; o<4; o++) {
          int ii = i + offset[o][0];
          int jj = j + offset[o][1];
          if(ii < 1 || ii > N || jj < 1 || jj > M) continue;
          if(viz[ii][jj][vizat]) {
            viz[i][j][1-vizat] = true;
            break;
          }
        }
      }
    }
  }
  
  vizat = 1-vizat;
  for(int i=1; i<=N; i++)
    for(int j=1; j<=M; j++)
      if(board[i][j] == '1' && viz[i][j][vizat]) {
        board[i][j] = '0';
      }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> M >> N;
  string s;
  getline(cin,s);
  for(int i=1; i<=N; i++) getline(cin, board[i]);
  for(int i=1; i<=N; i++) board[i] = "?" + board[i];
  viz[1][1][vizat] = true;
  fillzero();
  while(!viz[N][M][vizat]) {
    ans++;
    breakwalls();
    fillzero();
  }
  cout << ans << '\n';
}