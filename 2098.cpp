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

int N;
int adj[16][16];

struct D {
  map<pair<int,int>, int> m;
  D() {}
  bool exists(int a, int b) { return (m.find({a,b}) != m.end()); }
  int get(int a, int b) { return m[{a,b}]; }
  void save(int a, int b, int val) { m[{a,b}] = val; }
};

D d;

inline int min(int a, int b) { return a < b ? a : b; }

inline bool isOn(int i, int n) {
  return (i & (1 << n)) != 0;
}
inline int turnOn(int i, int n) {
  return i | (1 << n);
}
inline int turnOff(int i, int n) {
  return i & ~(1 << n);
}

int getD(int start, int visited) {
  if(d.exists(start, visited)) return d.get(start, visited);
  if(visited == (1<<N)-1) { // visited all
    if(adj[start][0] == 0) return INT_MAX;
    return adj[start][0];
  }

  int ans = INT_MAX;

  for(int next=0; next<N; next++) {
    if(isOn(visited, next) || adj[start][next] == 0) continue;
    int edge = adj[start][next];
    int then = getD(next, turnOn(visited, next));
    if(then == INT_MAX) continue;
    ans = min(ans, edge+then);
  }

  d.save(start, visited, ans);
  return ans;
}

int main() {
  scanf("%d", &N);
  for(int i=0; i<N; i++) for(int j=0; j<N; j++) scanf("%d", &adj[i][j]);

  int ans = getD(0, 1);

  printf("%d\n", ans);
}