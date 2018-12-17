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

int T, N;
double L, R;
double p[1001][1001]; // d[N][from its rightmost]
double rm[1001];

int main() {
  scanf("%d", &T);
  for(int t=0; t<T; t++) {
    scanf("%d %lf %lf", &N, &L, &R);
    double S = (1-L-R); // stay;
    rm[1] = R;
    p[1][0] = R+S; p[1][1] = L;
    for(int i=2; i<=N; i++) {
      p[i][0] = p[i-1][0]*(R+S) + p[i-1][1]*R;
      for(int j=1; j<=i; j++) {
        p[i][j] = p[i-1][j-1]*L + p[i-1][j]*S + p[i-1][j+1]*R;
      }
      rm[i] = (rm[i-1]+1)*R*p[i-1][0] + (rm[i-1])*(1-R*p[i-1][0]);
    }

    printf("%.4lf\n", rm[N]);
  }
}