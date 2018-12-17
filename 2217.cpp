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

using namespace std;

vector<int> rope;
int N;

int main() {
  scanf("%d", &N);
  rope.resize(N);
  for(int i=0; i<N; i++) scanf("%d", &rope[i]);
  sort(rope.begin(), rope.end(), greater<int>());

  int maxW = rope[0];
  int sumW = rope[0];
  for(int i=1; i<N; i++) {
    maxW = max(maxW, rope[i] * (i+1));
  }
  printf("%d\n", maxW);
}