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

int A[1000001];
int S[1000001];
long long C[1000001];
long long cnt;
int N, M;

// 게시판 참고함
int main() {
  scanf("%d %d", &N, &M);
  for(int i=1; i<=N; i++) scanf("%d", &A[i]);
  for(int i=1; i<=N; i++) {
    S[i] = (S[i-1]+A[i])%M;
    C[S[i]]++;
    if(S[i] == 0) cnt++;
  }
  for(int i=0; i<M; i++) {
    cnt += C[i]*(C[i]-1)/2;
  }

  printf("%lld\n", cnt);
}