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

struct Score {
  int s1, s2;
};

struct Comp {
  inline bool operator()(const Score& a, const Score& b) {
    return a.s1 < b.s1;
  }
};

int T,N;

int main() {
  scanf("%d", &T);
  for(int t=0; t<T; t++) {
    scanf("%d", &N);
    vector<Score> scores(N);
    vector<int> index(N+1);
    vector<int> minindex(N+1);
    vector<int> lds(N+1); // longest decreasing subsequence of index
    for(int i=0; i<N; i++) scanf("%d %d", &scores[i].s1, &scores[i].s2);
    sort(scores.begin(), scores.end(), Comp());
    for(int i=0; i<N; i++) index[scores[i].s2] = i;
    minindex[1] = index[1];
    for(int i=2; i<=N; i++) minindex[i] = min(minindex[i-1], index[i]);
    int ans = N;
    for(int i=2; i<=N; i++) if(index[i] > minindex[i-1]) ans--;
    printf("%d\n", ans);
  }
}