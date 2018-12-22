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

int N, M;
int package[50], each[50];
int d[106][50];

int main() {
  scanf("%d %d", &N, &M);
  for(int i=0; i<M; i++) scanf("%d %d", &package[i], &each[i]);
  for(int i=1; i<=N+5; i++) {
    d[i][0] = d[i-1][0]+each[0];
    if(i >= 6) d[i][0] = min(d[i][0], d[i-6][0]+package[0]);
    for(int j=1; j<M; j++) {
      d[i][j] = d[i][j-1];
      d[i][j] = min(d[i][j], d[i-1][j]+each[j]);
      if(i>=6) d[i][j] = min(d[i][j], d[i-6][j]+package[j]);
    }
  }
  int ans = d[N][M-1];
  for(int i=1; i<6; i++) ans = min(ans,d[N+i][M-1]);
  printf("%d\n", ans);
}