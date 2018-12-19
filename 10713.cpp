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

int N, M;
int travel[100001];
int ticket[100000], useIC[100000], buyIC[100000];
int useTrain[100000];
long long ans;

int main() {
  scanf("%d %d", &N, &M);
  for(int i=1; i<=M; i++) scanf("%d", &travel[i]);
  for(int i=1; i<N; i++) scanf("%d %d %d", &ticket[i], &useIC[i], &buyIC[i]);
  
  for(int i=1; i<M; i++) {
    int from = travel[i];
    int to = travel[i+1];
    if(from > to) swap(from, to);
    useTrain[from]++;
    useTrain[to]--;
  }
  for(int i=1; i<N; i++) useTrain[i] += useTrain[i-1];

  for(int i=1 ;i<N; i++) {
    if(useTrain[i] == 0) continue;
    ans += min((long long)ticket[i] * useTrain[i], buyIC[i] + (long long)useIC[i] * useTrain[i]);
  }

  printf("%lld\n", ans);
}