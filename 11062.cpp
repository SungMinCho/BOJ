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

using namespace std;

int T, N;
int cards[1001];
int d[1001][1001]; // optimal of d[start][end]
int sum[1001];

int main() {
  scanf("%d", &T);
  for(int t=0; t<T; t++) {
    scanf("%d", &N);
    for(int i=1; i<=N; i++) scanf("%d", &cards[i]);
    sum[0] = 0;
    for(int i=1; i<=N; i++) sum[i] = sum[i-1] + cards[i];

    for(int i=1; i<=N; i++) d[i][i] = cards[i];
    for(int gap=1; gap<N; gap++) {
      for(int start=1; start<=N-gap; start++) {
          int end = start+gap;
          int s = sum[end] - sum[start-1];
          d[start][end] = max(s - d[start+1][end],
                              s - d[start][end-1]);
      }
    }

    printf("%d\n", d[1][N]);
  }
}