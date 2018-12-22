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

int d[101][101];
int N, M;

int main() {
  scanf("%d %d", &N, &M);
  for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) d[i][j] = 987654321;
  for(int i=1; i<=N; i++) d[i][i] = 0;
  for(int i=0; i<M; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    d[a][b] = d[b][a] = 1;
  }

  for(int k=1; k<=N; k++) {
    for(int a=1; a<N; a++) {
      for(int b=a+1; b<=N; b++) {
        d[a][b] = d[b][a] = min(d[a][b], d[a][k] + d[k][b]);
      }
    }
  }

  int ans = 0, anskb = INT_MAX;
  for(int i=1; i<=N; i++) {
    int cnt = 0;
    for(int j=1; j<=N; j++) cnt += d[i][j];
    if(cnt < anskb) {
      anskb = cnt;
      ans = i;
    }
  }
  printf("%d\n", ans);
}