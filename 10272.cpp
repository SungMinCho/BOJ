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

struct Pos {
  int x, y;
};

inline double getDist(const Pos& a, const Pos& b) {
  return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int T, N;
Pos planet[513];
double d[513][513]; // last in LR, last in RL

int main() {
  scanf("%d", &T);
  for(int t=0; t<T; t++) {
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
      scanf("%d %d", &planet[i].x, &planet[i].y);
    }
    for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) d[i][j] = 99999999.0;
    d[1][1] = 0.0;
    for(int i=1; i<=N; i++) {
      for(int j=1; j<=N; j++) {
        if(i==j && i != 1) continue;
        int v = max(i,j)+1;
        if(v > N) continue;
        d[i][v] = min(d[i][v], d[i][j] + getDist(planet[j], planet[v]));
        d[v][j] = min(d[v][j], d[i][j] + getDist(planet[i], planet[v]));
        d[v][v] = min(d[v][v], d[i][j] + getDist(planet[i], planet[v]) + getDist(planet[j], planet[v]));
      }
    }
    printf("%lf\n", d[N][N]);
  }
}