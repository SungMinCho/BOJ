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

int coins[10];
int N, K;

int main() {
  scanf("%d %d", &N, &K);
  for(int i=0; i<N; i++) scanf("%d", &coins[i]);
  int cnt = 0;
  for(int i=N-1; i>=0; i--) {
    cnt += (K / coins[i]);
    K %= coins[i];
  }
  printf("%d\n", cnt);
}