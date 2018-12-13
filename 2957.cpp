#include <stdio.h>
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

int n;
long long cnt;
map<int, int> depth;

inline int max(int a, int b) { return a > b ? a : b; }

int main() {
  scanf("%d", &n);
  int r;
  scanf("%d", &r);
  printf("0\n");
  depth[r] = 0;
  for(int i=0; i<n-1; i++) {
    scanf("%d", &r);
    auto right = depth.upper_bound(r);
    auto left = right;

    if(right->first == 0) { // no right
      left--;
      depth[r] = left->second + 1;
    } else if(left == depth.begin()) { //no left
      depth[r] = right->second + 1;
    } else { // have both
      left--;
      depth[r] = max(left->second, right->second) + 1;
    }
    cnt += depth[r];

    printf("%lld\n", cnt);
  }
}