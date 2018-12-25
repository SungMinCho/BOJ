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
#include <assert.h>

using namespace std;

struct Edge {
  int from, to, dist;
  Edge(int f, int t, int d) : from(f), to(t), dist(d) {}
};

struct DS {
  vector<int> parent;
  DS(int n) : parent(n+1) { for(int i=1; i<=n; i++) parent[i] = i; }
  int root(int x) {
    if(x==parent[x]) return x;
    return parent[x]=root(parent[x]);
  }
  void merge(int a, int b) {
    int ra = root(a); int rb = root(b);
    if(ra != rb) parent[ra] = rb;
  }
};

int V, E;

int main() {
  scanf("%d %d", &V, &E);
  vector<Edge> edges;
  for(int i=0; i<E; i++) {
    int a, b, c; scanf("%d %d %d", &a, &b, &c);
    edges.push_back(Edge(a,b,c));
  }
  sort(edges.begin(), edges.end(), [](const auto& a, const auto& b) {
    return a.dist < b.dist;
  });

  DS ds(V);
  int total = 0;
  for(auto& edge : edges) {
    if(ds.root(edge.from) != ds.root(edge.to)) {
      ds.merge(edge.from, edge.to);
      total += edge.dist;
    }
  }
  printf("%d\n", total);
}