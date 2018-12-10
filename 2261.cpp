#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

#define MAXN 100005

int n;
int dd = INT_MAX;

struct point {
  int x, y;
};

vector<point> points;

int lowbound(int lo, int hi, double axis) {
  if(lo == hi) {
    double dist = axis - points[lo].x;
    if(dist*dist <= dd) return lo;
    return -1;
  }
  int mid = (lo+hi)/2;
  double dist = axis - points[mid].x;
  if(dist*dist > dd) return lowbound(mid+1, hi, axis);
  else return lowbound(lo, mid, axis);
}

int highbound(int lo, int hi, double axis) {
  if(lo > hi) return -1;
  if(lo == hi) {
    double dist = points[lo].x - axis;
    if(dist*dist <= dd) return lo;
    return -1;
  }
  if(lo + 1 == hi) {
    double distlo = points[lo].x - axis;
    double disthi = points[hi].x - axis;
    if(distlo*distlo > dd) return -1;
    else if(disthi*disthi > dd) return lo;
    else return hi;
  }
  int mid = (lo+hi)/2;
  double dist = points[mid].x - axis;
  if(dist*dist > dd) return highbound(lo, mid-1, axis);
  else return highbound(mid,hi, axis);
}

int min(int a, int b) {
  if(a<b) return a;
  return b;
}

void getmindd(int lo, int hi) {
  if(lo >= hi) return;
  if(lo+1 == hi) {
    int xdist = points[hi].x - points[lo].x;
    int ydist = points[hi].y - points[lo].y;
    int ddcand = xdist*xdist + ydist*ydist;
    if(ddcand < dd) dd = ddcand;
    return;
  }

  int mid = (lo+hi)/2;
  double axis = (points[mid].x + points[mid+1].x) / 2;

  getmindd(lo, mid);
  getmindd(mid+1, hi);

  int lb = lowbound(lo, mid, axis);
  int rb = highbound(mid+1, hi, axis);
  if(lb==-1 && rb==-1) return;
  else {
    if(lb==-1) lb = mid+1;
    if(rb==-1) rb = mid;
    vector<point> ps(&points[lb], &points[rb+1]);
    sort(ps.begin(), ps.end(), [](const point& a, const point& b) { return a.y < b.y; });
    for(int i=0; i<ps.size()-1; i++) {
      for(int j=i+1; j<ps.size(); j++) {
        int ydist = ps[j].y - ps[i].y;
        if(ydist*ydist >= dd) break;
        int xdist = ps[j].x - ps[i].x;
        int ddcand = xdist*xdist + ydist*ydist;
        if(ddcand < dd) dd = ddcand;
      }
    }
  }
}

int main() {
  scanf("%d", &n);
  points.resize(n);
  for(int i=0; i<n; i++) scanf("%d %d", &(points[i].x), &(points[i].y));
  sort(points.begin(), points.end(), [](const point& a, const point& b) { return a.x < b.x; });

  getmindd(0,n-1);
  printf("%d\n", dd);
}
