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
int d[101][101];

int main() {
  scanf("%d %d", &N, &M);
  for(int i=1; i<N; i++) for(int j=i+1; j<=N; j++) d[i][j] = d[j][i] = 987654321;
  for(int i=0; i<M; i++){
    int a, b, c; scanf("%d %d %d", &a, &b, &c);
    d[a][b] = min(d[a][b],c);
  }
  for(int k=1; k<=N; k++) {
    for(int i=1; i<=N; i++) {
      for(int j=1; j<=N; j++) {
        d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
      }
    }
  }

  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      if(d[i][j] == 987654321) printf("0 ");
      else printf("%d ", d[i][j]);
    }
    printf("\n");
  }
}