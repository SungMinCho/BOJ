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
  int dist;
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

struct Star {
  int x, y, z, index;
};

int stardist(const Star& a, const Star& b) {
  int x = abs(a.x-b.x);
  int y = abs(a.y-b.y);
  int z = abs(a.z-b.z);
  return min(x, min(y,z));
}

int V;
vector<Star> stars;

int main() {
  scanf("%d", &V);
  stars.resize(V+1);
  for(int i=1; i<=V; i++) {
    scanf("%d %d %d", &stars[i].x, &stars[i].y, &stars[i].z);
    stars[i].index = i;
  }
  vector<Edge> edges;

  sort(stars.begin()+1, stars.end(), [](const auto& a, const auto& b) {
    return a.x < b.x;
  });
  for(int i=1; i<V; i++) {
    edges.push_back(Edge(stars[i].index,stars[i+1].index,stardist(stars[i],stars[i+1])));
  }
  sort(stars.begin()+1, stars.end(), [](const auto& a, const auto& b) {
    return a.y < b.y;
  });
  for(int i=1; i<V; i++) {
    edges.push_back(Edge(stars[i].index,stars[i+1].index,stardist(stars[i],stars[i+1])));
  }
  sort(stars.begin()+1, stars.end(), [](const auto& a, const auto& b) {
    return a.z < b.z;
  });
  for(int i=1; i<V; i++) {
    edges.push_back(Edge(stars[i].index,stars[i+1].index,stardist(stars[i],stars[i+1])));
  }

  sort(edges.begin(), edges.end(), [](const auto& a, const auto& b) {
    return a.dist < b.dist;
  });

  DS ds(V);
  long long total = 0;
  for(auto& edge : edges) {
    if(ds.root(edge.from) != ds.root(edge.to)) {
      ds.merge(edge.from, edge.to);
      total += edge.dist;
    }
  }
  printf("%lld\n", total);
}