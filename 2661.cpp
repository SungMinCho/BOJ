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

vector<int> ans;
int N;

inline bool validate(int at) {
  for(int len=1; 2*len <= at+1; len++) {
    bool allSame = true;
    for(int i=0; i<len; i++) {
      if(ans[at-i] != ans[at-len-i]) {
        allSame = false;
        break;
      }
    }
    if(allSame) return false;
  }
  return true;
}

bool solve(int at) {
  if(at == N) {
    return true;
  }
  for(int i=1; i<=3; i++) {
    ans[at] = i;
    if(validate(at)) {
      if(solve(at+1)) return true;
    }
  }
  return false;
}

int main() {
  cin >> N;
  ans.resize(N);
  solve(0);
  for(auto i : ans) cout << i;
  cout << endl;
}