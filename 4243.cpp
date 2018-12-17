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
#include <cmath>

using namespace std;

typedef long long ll;

int dist[100];
int sumDist[100]; // sumDist[i] = t[1, i]
int A,N,T;
ll d[102][102][102];

ll getD(int at, int lower, int upper) {
  if(lower == 0 && upper == N+1) return 0;
  if(d[at][lower][upper] != -1) return d[at][lower][upper];

  int unvisited = lower + (N-upper+1);
  int moveLeft = sumDist[at] - sumDist[lower];
  int moveRight = sumDist[upper] - sumDist[at];

  if(lower == 0) {
    return d[at][lower][upper] = getD(upper, lower, upper+1)+((ll)moveRight*unvisited);
  }
  if(upper == N+1) {
    return d[at][lower][upper] = getD(lower, lower-1, upper)+((ll)moveLeft*unvisited);
  }
  return d[at][lower][upper] = min(getD(lower,lower-1,upper)+((ll)moveLeft*unvisited),
                                   getD(upper,lower,upper+1)+((ll)moveRight*unvisited));
}


int main() {
  scanf("%d", &T);
  for(int t=0; t<T; t++) {
    scanf("%d %d", &N, &A);

    for(int i=1; i<N; i++) scanf("%d", &dist[i]); // dist[i] = t[i,i+1]
    for(int i=2; i<=N; i++) sumDist[i] = sumDist[i-1] + dist[i-1];
    for(int i=0; i<=N+1; i++) for(int j=0; j<=N+1; j++) for(int k=0; k<=N+1; k++) d[i][j][k] = -1;

    printf("%lld\n", getD(A,A,A));
  }
}