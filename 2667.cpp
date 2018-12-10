#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

int n, m;
char board[26][26];
bool viz[26][26];
int cnt;
int offset[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

void fill(int i, int j) {
  if(viz[i][j]) return;
  if(board[i][j] == '0') return;
  viz[i][j] = true;
  cnt++;
  for(int o=0; o<4; o++) {
    fill(i+offset[o][0], j+offset[o][1]);
  }
}

int main() {
  cin >> n;
  for(int i=1; i<=n; i++) cin >> board[i]+1;
  for(int i=0; i<=n+1; i++) viz[i][0] = viz[i][n+1] = viz[0][i] = viz[n+1][i] = true;

  vector<int> cnts;
  for(int i=1; i<=n; i++) {
    for(int j=1; j<=n; j++) {
      if(board[i][j] == '1' && !viz[i][j]) {
        cnt = 0;
        fill(i,j);
        cnts.push_back(cnt);
      }
    }
  }

  sort(cnts.begin(), cnts.end());

  cout << cnts.size() << endl;
  for(auto c : cnts) cout << c << endl;

  return 0;
}
