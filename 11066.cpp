#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

int T, K;
int C[502];
int S[502];
int D[502][502];

inline int min(int a,int b) {
  if(a<b) return a;
  return b;
}

int main() {
  scanf("%d", &T);
  for(int t=0; t<T; t++) {
    scanf("%d", &K);
    for(int k=1; k<=K; k++) scanf("%d", &C[k]);
    for(int k=1; k<=K; k++) S[k] = S[k-1] + C[k];

    for(int length=1; length <= K-1; length++) {
      for(int i=1; i <= K-length; i++) {
        int j = i + length;
        D[i][j] = INT_MAX;
        for(int divide=i; divide < j; divide++) {
          int S1 = S[divide]-S[i-1];
          int S2 = S[j] - S[divide];
          D[i][j] = min(D[i][j], D[i][divide] + D[divide+1][j] + S1 + S2);
        }
      }
    }

    printf("%d\n", D[1][K]);
  }
}
