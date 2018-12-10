#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

#define MAXN 105

typedef long long ll;

int board[MAXN][MAXN];
ll d[MAXN][MAXN];
int N;

bool inside(int i, int j) {
  return 1 <= i && i <= N && 1 <= j && j <= N;
}

int main() {
  scanf("%d", &N);

  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      scanf("%d", &board[i][j]);
    }
  }

  for(int i=N; i>=1; i--) {
    for(int j=N; j>=1; j--) {
      if(board[i][j] == 0) {
        if(i==N && j == N) d[i][j] = 1;
        continue;
      }

      int jump = board[i][j];
      int ii, jj;
      ii = i + jump;
      jj = j;
      if(inside(ii,jj)) d[i][j] += d[ii][jj];
      ii = i;
      jj = j + jump;
      if(inside(ii,jj)) d[i][j] += d[ii][jj];
    }
  }

  cout << d[1][1] << endl;
}

