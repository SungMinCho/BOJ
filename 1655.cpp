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

int N;
vector<int> v;

int main() {
  scanf("%d", &N);
  for(int i=0; i<N; i++) {
    int x;
    scanf("%d", &x);
    auto it = lower_bound(v.begin(), v.end(), x);
    v.insert(it, x);
    if(v.size() % 2 == 1) printf("%d\n", v[v.size()/2]);
    else printf("%d\n", min(v[v.size()/2-1], v[v.size()/2]));
  }
}