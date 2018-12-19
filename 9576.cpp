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

using namespace std;

int adj[1001][1001];
int people, books, T;
int giveTo[1001];
vector<bool> viz;

bool match(int here) {
  for(int there=1; there<=books; there++) {
    if(adj[here][there] && !viz[there]) {
      viz[there] = true;
      if(!giveTo[there] || match(giveTo[there])) {
        giveTo[there] = here;
        return true;
      }
    }
  }
  return false;
}

int maxmatch() {
  int total = 0;
  for(int i=1; i<=people; i++) {
    viz.clear();
    viz.resize(books+1, false);
    if(match(i)) total++;
  }
  return total;
}

int main() {
  scanf("%d", &T);
  for(int t=0; t<T; t++) {
    scanf("%d %d", &books, &people);
    for(int i=1; i<=people; i++) for(int j=1; j<=books; j++) adj[i][j] = 0;
    for(int j=1; j<=books; j++) giveTo[j] = 0;
    for(int i=1; i<=people; i++) {
      int a, b; scanf("%d %d", &a, &b);
      for(int j=a; j<=b; j++) adj[i][j] = 1;
    }

    printf("%d\n", maxmatch());
  }
}