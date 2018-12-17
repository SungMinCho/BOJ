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

vector<int> cost;
int N;

int main() {
  scanf("%d", &N);
  cost.resize(N);
  for(int i=0; i<N; i++) scanf("%d", &cost[i]);
  sort(cost.begin(), cost.end());
  int m = N;
  int ans = 0;
  for(auto c : cost) {
    ans += c*m;
    m--;
  }
  printf("%d\n", ans);
}