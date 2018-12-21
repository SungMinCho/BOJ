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

struct Point {
  int x, y;
  long long dist;
  double angle;
};

struct Comp {
  int by;
  Comp(int by_) : by(by_) {}
  inline bool operator()(const Point& a, const Point& b) {
    if(by == 0) {
      if(a.x == b.x) return a.y < b.y;
      return a.x < b.x;
    }
    if(a.y == b.y) return a.x < b.x;
    return a.y < b.y;
  }
};

struct CompByAngle {
  inline bool operator()(const Point& a, const Point& b) {
    if(a.angle == b.angle) return a.dist < b.dist;
    return a.angle < b.angle;
  }
};

double cos2(const Point& a, const Point& b) {
  double u = ((long long)a.x-b.x)*((long long)a.x-b.x);
  double v = u + ((long long)a.y-b.y)*((long long)a.y-b.y);
  u *= (b.x > a.x ? 1.0 : -1.0);
  // assert v != 0
  return u/v;
}

long long dist(const Point& a, const Point& b) {
  return ((long long)a.x-b.x)*((long long)a.x-b.x) +
         ((long long)a.y-b.y)*((long long)a.y-b.y);
}

vector<Point> points;
int N;
vector<Point> hull;

bool atRight(const Point& a, const Point& b, const Point& c) {
  long long x1 = (long long)b.x-a.x; long long y1 = (long long)b.y-a.y;
  long long x2 = (long long)c.x-a.x; long long y2 = (long long)c.y-a.y;
  long long cross = x1*y2 - y1*x2;
  return cross < 0;
}

int main() {
  scanf("%d", &N);
  points.resize(N);
  for(int i=0; i<N; i++) {
    scanf("%d %d", &points[i].x, &points[i].y);
  }
  sort(points.begin(), points.end(), Comp(1));
  for(int i=1; i<points.size(); i++) {
    points[i].angle = cos2(points[0], points[i]);
    points[i].dist = dist(points[0], points[i]);
  }
  sort(points.begin()+1, points.end(), CompByAngle());

  for(auto& p : points) {
    if(hull.size() < 2) {
      hull.push_back(p);
    } else {
      int s = hull.size();
      while((s=hull.size())>=2 && !atRight(hull[s-2],hull[s-1],p)) hull.resize(s-1);
      hull.push_back(p);
    }
  }

  printf("%lu\n", hull.size());
}