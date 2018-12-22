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

int maxans = INT_MIN;
int minans = INT_MAX;

int N;
vector<int> nums;
vector<int> ops(4);

void backtrack(int at, int val) {
  if(at == N) {
    maxans = max(maxans, val);
    minans = min(minans, val);
    return;
  }

  for(int i=0; i<4; i++) {
    if(ops[i] > 0) {
      ops[i]--;
      if(i==0) backtrack(at+1, val+nums[at]);
      else if(i==1) backtrack(at+1, val-nums[at]);
      else if(i==2) backtrack(at+1, val*nums[at]);
      else if(i==3) backtrack(at+1, val/nums[at]);
      ops[i]++;
    }
  }
}

int main() {
  scanf("%d", &N);
  nums.resize(N); for(int i=0; i<N; i++) scanf("%d", &nums[i]);
  for(int i=0; i<4; i++) scanf("%d", &ops[i]);
  backtrack(1,nums[0]);
  printf("%d\n%d\n", maxans, minans);
}