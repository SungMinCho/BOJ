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
  int from, to;
  double dist;
  Edge(int f, int t, double d) : from(f), to(t), dist(d) {}
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

struct Star {
  double x, y;
};

int V ;
vector<Star> stars;

int main() {
  scanf("%d", &V);
  stars.resize(V+1);
  for(int i=1; i<=V; i++) {
    scanf("%lf %lf", &stars[i].x, &stars[i].y);
  }
  vector<Edge> edges;
  for(int i=1; i<V; i++) {
    for(int j=i+1; j<=V; j++) {
      double x = stars[j].x - stars[i].x;
      double y = stars[j].y - stars[i].y;
      double d = sqrt(x*x+y*y);
      edges.push_back(Edge(i,j,d));
    }
  }
  sort(edges.begin(), edges.end(), [](const auto& a, const auto& b) {
    return a.dist < b.dist;
  });

  DS ds(V);
  double total = 0;
  for(auto& edge : edges) {
    if(ds.root(edge.from) != ds.root(edge.to)) {
      ds.merge(edge.from, edge.to);
      total += edge.dist;
    }
  }
  printf("%lf\n", total);
}