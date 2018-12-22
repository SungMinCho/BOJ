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

priority_queue<int, vector<int>, greater<int>> pq;
int N;

int main() {
  scanf("%d", &N);
  for(int i=0; i<N; i++) {
    int x; scanf("%d", &x);
    if(x==0) {
      if(pq.empty()) printf("0\n");
      else {
        printf("%d\n", pq.top());
        pq.pop();
      }
    } else pq.push(x);
  }
}