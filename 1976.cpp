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
#include <assert.h>

using namespace std;

int N, M;
int reachable[201][201];

int main() {
  scanf("%d %d", &N, &M);
  for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) scanf("%d", &reachable[i][j]);
  for(int i=1; i<=N; i++) reachable[i][i] = 1;
  for(int k=1; k<=N; k++) {
    for(int i=1; i<=N; i++) {
      for(int j=1; j<=N; j++) {
        reachable[i][j] |= (reachable[i][k] && reachable[k][j]);
      }
    }
  }

  bool able = true;
  int last; scanf("%d", &last);
  for(int i=1; i<M; i++) {
    int cur; scanf("%d", &cur);
    if(!reachable[last][cur]) able = false;
    last = cur;
  }
  if(able) printf("YES\n");
  else printf("NO\n");
}