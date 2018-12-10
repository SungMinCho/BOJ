#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

#define MAXN 32001
#define MAXM 100001

int N;

vector<vector<int>> depend;
vector<int> order;
vector<int> takeTime;
vector<int> maxdepthsave;

int max(int a, int b) { return a > b ? a : b; }

int maxdepth(int of) {
  if(maxdepthsave[of] != -1) return maxdepthsave[of];

  int md = takeTime[of];
  int add = 0;
  for(auto d : depend[of]) add = max(add, maxdepth(d));
  return (maxdepthsave[of] = md + add);
}

int main() {
  scanf("%d", &N);
  depend.resize(N+1);
  takeTime.resize(N+1);
  for(int i=1; i<=N; i++) {
    scanf("%d", &takeTime[i]);
    while(true) {
      int b;
      scanf("%d", &b);
      if(b == -1) break;
      depend[i].push_back(b);
    }
  }

  maxdepthsave.resize(N+1, -1);
  for(int i=1; i<=N; i++) cout << maxdepth(i) << endl;
}
