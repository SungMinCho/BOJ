#include <stdio.h>
#include <tuple>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>
#include <climits>
#include <stdlib.h>
#include <cstring>

using namespace std;

int N, K;
int colors[201];
int len;
int d[201][201][21];

int main() {
  scanf("%d %d", &N, &K);

  for(int i=1; i<=N; i++) {
    int c;
    scanf("%d", &c);
    if(len==0 || colors[len] != c) colors[++len] = c;
  }

  for(int i=1; i<=len; i++) for(int c=1; c<=K; c++) {
    if(colors[i] == c) d[i][i][c] = 0;
    else d[i][i][c] = 1;
  }

  for(int gap=1; gap<len; gap++) {
    for(int i=1; i<=len-gap; i++) {
      int j = i+gap;
      int dij_min = 999999;
      for(int c=1; c<=K; c++) {
        d[i][j][c] = 999999;
        for(int k=i; k<j; k++) {
          d[i][j][c] = min(d[i][j][c], d[i][k][c] + d[k+1][j][c]);
        }
        dij_min = min(dij_min, d[i][j][c]);
      }
      for(int c=1; c<=K; c++) {
        d[i][j][c] = min(d[i][j][c], dij_min+1);
      }
    }
  }

  int ans = 999999;
  for(int c=1; c<=K; c++) ans = min(ans, d[1][len][c]);
  printf("%d\n", ans);
}