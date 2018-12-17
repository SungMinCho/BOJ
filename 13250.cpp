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

long double d[1000001];
int N;

long double getD(int N) {
  if(N < 1) return 0;
  if(d[N] != 0.0) return d[N];
  if(N == 1) return d[N] = 1.0;

  d[N] = 1.0;
  for(int i=1; i<=6; i++) {
    d[N] += 1.0/6.0*getD(N-i);
  }
  return d[N];
}

int main() {
  scanf("%d", &N);

  printf("%.10Lf\n", getD(N));
}