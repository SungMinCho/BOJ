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

int N, K;
int d[100001];
bool viz[100001];
queue<int> q;
int cnt;

inline void insert(queue<int>& q, int at) {
  if(at >= 0 && at <=100000 && !viz[at]) {
    viz[at] = true; q.push(at); d[at] = cnt;
  }
}

int main() {
  scanf("%d %d", &N, &K);
  insert(q, K);
  while(!q.empty()) {
    cnt++;
    queue<int> qq;
    while(!q.empty()) {
      int at = q.front(); q.pop();
      insert(qq,at-1);
      insert(qq,at+1);
      if(at % 2 == 0) insert(qq,at/2);
    }
    if(viz[N]) break;
    q = qq;
  }
  printf("%d\n", d[N]);
}