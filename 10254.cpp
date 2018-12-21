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

typedef long long ll;

struct Point {
  int x, y;
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

// positive if a-b -> a-c is clockwise.
ll dir(const Point& a, const Point& b, const Point& c) {
  ll x1 = (ll)b.x-a.x; ll y1 = (ll)b.y-a.y;
  ll x2 = (ll)c.x-a.x; ll y2 = (ll)c.y-a.y;
  return x2*y1-x1*y2;
}

ll dist(const Point& a, const Point& b) {
  ll x = (ll)b.x-a.x; ll y = (ll)b.y-a.y;
  return x*x+y*y;
}

Point ansa, ansb;
int T, N;

void monotone(vector<Point>& points) {
  sort(points.begin(), points.end(), Comp(0));
  vector<Point> U, L;
  for(int k=0; k<points.size(); k++) {
    while(U.size() > 1 && dir(U[U.size()-2], U[U.size()-1], points[k]) <= 0) U.resize(U.size()-1);
    while(L.size() > 1 && dir(L[L.size()-2], L[L.size()-1], points[k]) >= 0) L.resize(L.size()-1);
    U.push_back(points[k]);
    L.push_back(points[k]);
  }

  ll maxd = 0;
  int i = 0;
  int j =L.size()-1;
  while(i <= U.size()-1 && j >= 0) {
    ll d = dist(U[i],L[j]);
    if(d > maxd) {
      maxd = d; ansa = U[i]; ansb = L[j];
    }

    if(i == U.size()) j--;
    else if(j == 0) i++;
    else if( ((ll)U[i+1].y-U[i].y)*((ll)L[j].x-L[j-1].x) >
             ((ll)U[i+1].x-U[i].x)*((ll)L[j].y-L[j-1].y) ) i++;
    else j--;
  }
}

int main() {
  scanf("%d", &T);
  for(int t=0; t<T; t++) {
    scanf("%d", &N);
    vector<Point> points(N);
    for(int i=0; i<N; i++) scanf("%d %d", &points[i].x, &points[i].y);
    monotone(points);
    printf("%d %d %d %d\n", ansa.x, ansa.y, ansb.x, ansb.y);
  }
}