#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

#define MAXN 100002

int T, N, L, K;
int ids[MAXN];
int leftFallTime[MAXN];
int rightFallTime[MAXN];
int leftnum, rightnum;

inline int min(int a,int b) {
  if(a<b) return a;
  return b;
}

int main() {
  scanf("%d", &T);
  for(int t=0; t<T; t++) {
    scanf("%d %d %d", &N, &L, &K);

    leftnum = 0;
    rightnum = 0;

    int pos, aId;

    for(int i=1; i<=N; i++) {
      scanf("%d %d", &pos, &ids[i]);
      if(ids[i] > 0) {
        rightFallTime[++rightnum] = L-pos;
      } else {
        leftFallTime[++leftnum] = pos;
      }
    }

    int head = 1;
    int tail = N;
    int cnt = 0;
    int fallidindex;
    while(cnt < K) {
      cnt++;
      if(head > leftnum) {
        fallidindex = tail--;
      } else if(tail-leftnum < 1) {
        fallidindex = head++;
      } else if(leftFallTime[head] < rightFallTime[tail-leftnum]) {
        fallidindex = head++;
      } else if(leftFallTime[head] > rightFallTime[tail-leftnum]) {
        fallidindex = tail--;
      } else if(ids[head] < ids[tail]) {
        fallidindex = head++;
      } else {
        fallidindex = tail--;
      }
    }

    printf("%d\n", ids[fallidindex]);
  }
}
