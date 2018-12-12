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

typedef long long ll;

int n, m;
vector<ll> v;

bool canMake(ll length) {
  if(length == 0) return true;
  int pieces = 0;
  for(auto stick : v) {
    pieces += stick / length;
  }
  if(pieces >= m) return true;
  return false;
}

int binSearch(ll lo, ll hi) {
  if(lo == hi) return lo;
  int mid = (lo+hi)/2+1;
  if(canMake(mid)) return binSearch(mid, hi);
  else return binSearch(lo, mid-1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;
  v.resize(n);
  for(int i=0; i<n; i++) cin >> v[i];

  cout << binSearch(0, INT_MAX) << '\n';
}