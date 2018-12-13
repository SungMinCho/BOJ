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

int n, N;
vector<int> ans;
vector<int> depth;

int main() {
  scanf("%d", &N);
  ans.resize(1);
  depth.resize(1);
  ans[0] = 1;
  depth[0] = 0;
  n = 1;
  int sz = 1;
  while(n < N) {
    ans.resize(sz*2 + 1);
    depth.resize(sz*2 + 1);
    for(int i=sz-1; i>=0; i--) {
      ans[i+1] = ans[i]*2;
      ans[i+sz+1] = ans[i+1] + 1;
      depth[i+sz+1] = depth[i+1] = depth[i]+1;
    }
    ans[0] = 1;
    for(int i=0; i<sz; i++) {
      if(depth[i+1] == n) swap(ans[i+1], ans[i+1+sz]);
    }

    sz = sz*2 + 1;
    n += 1;
  }


  for(auto a : ans) printf("%d ", a);
  printf("\n");
}