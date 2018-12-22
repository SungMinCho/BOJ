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

int N, M, X;
int d[1001][1001];

int main() {
  scanf("%d %d %d", &N, &M, &X);
  for(int i=1; i<N; i++) for(int j=i+1; j<=N; j++) d[i][j] = d[j][i] = 987654321;

  for(int i=0; i<M; i++) {
    int a, b, t;
    scanf("%d %d %d", &a, &b, &t);
    d[a][b] = t;
  }
  
  for(int k=1; k<=N; k++) {
    for(int i=1; i<=N; i++) {
      for(int j=1; j<=N; j++) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  int ans = d[1][X] + d[X][1];
  for(int i=2; i<=N; i++) ans = max(ans, d[i][X]+d[X][i]);
  printf("%d\n", ans);
}