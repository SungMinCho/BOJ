#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

#define MAXN 100005
typedef long long ll;

int N;
ll h[MAXN];
int leftmost[MAXN];
int rightmost[MAXN];

ll max(ll a, ll b){
  if(a>b) return a;
  return b;
}

ll min(ll a, ll b){
  if(a<b) return a;
  return b;
}

ll maxarea(int lo, int hi) {
  if(lo == hi) return h[lo];
  
  ll ret;
  int mid = (lo+hi)/2;
  ret = max(maxarea(lo, mid), maxarea(mid+1, hi));

  int height_index;
  if(h[mid] < h[mid+1]) height_index = mid;
  else height_index = mid+1;
  ll height = h[height_index];
  int lm = leftmost[height_index];
  int rm = rightmost[height_index];

  ret = max(ret, (rm-lm+1)*height);

  return ret;
}

int main() {
  while(true) {
    scanf("%d", &N);
    if(N==0) break;
    for(int i=0; i<N; i++) scanf("%lld", &h[i]);

    leftmost[0] = 0;
    for(int i=1; i<N; i++) {
      if(h[i-1] < h[i]) leftmost[i] = i;
      else if(h[i-1] == h[i]) leftmost[i] = leftmost[i-1];
      else {
        int j = i;
        while(h[j-1] > h[i] && j >= 1) j = leftmost[j-1];
        if(j==0) leftmost[i] = 0;
        else if(h[j-1] == h[i]) leftmost[i] = leftmost[j-1];
        else leftmost[i] = j;
      }
    }

    rightmost[N-1] = N-1;
    for(int i=N-2; i>=0; i--) {
      if(h[i+1] < h[i]) rightmost[i] = i;
      else if(h[i+1] == h[i]) rightmost[i] = rightmost[i+1];
      else {
        int j = i;
        while(h[j+1] > h[i] && j <= N-2) j = rightmost[j+1];
        if(j==N-1) rightmost[i] = N-1;
        else if(h[j+1] == h[i]) rightmost[i] = rightmost[j+1];
        else rightmost[i] = j;
      }
    }

    printf("%lld\n", maxarea(0, N-1));
  }
}
