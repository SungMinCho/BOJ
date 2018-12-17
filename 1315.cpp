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

#define MAXN 1001

int STR[MAXN], INT[MAXN], PNT[MAXN];
int N, ans;
int freePnt[MAXN][MAXN];
bool can[MAXN][MAXN];

// 이건 솔루션 참고함...
int main() {
  scanf("%d", &N);
  for(int i=1; i<=N; i++) {
    scanf("%d %d %d", &STR[i], &INT[i], &PNT[i]);
  }

  for(int S=1; S<=1000; S++) {
    for(int I=1; I<=1000; I++) {
      freePnt[S][I] = 2-S-I;
      int quest = 0;
      for(int x=1; x<=N; x++) {
        if(STR[x] <= S || INT[x] <= I) {
          freePnt[S][I] += PNT[x];
          quest++;
        }
      }

      can[S][I] = (S==1 && I==1) || (S>1 && can[S-1][I] && freePnt[S-1][I]>0) || (I>1 && can[S][I-1] && freePnt[S][I-1]>0);
      if(can[S][I]) ans = max(ans, quest);
    }
  }

  printf("%d\n", ans);
}