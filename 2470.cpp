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

using namespace std;

int n;
vector<int> v;

inline int abs(int a) { return a < 0 ? -a : a; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  v.resize(n);
  for(int i=0; i<n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  int alo = 0, ahi = n-1, ans = abs(v[0]+v[n-1]);
  int lo = 0, hi = n-1;
  while(lo < hi) {
    int sum = v[lo] + v[hi];
    int asum = abs(sum);
    if(asum < ans) {
      ans = asum, alo = lo, ahi = hi;
    }
    if(sum < 0) lo++;
    else hi--;
  }

  cout << v[alo] << ' ' << v[ahi] << '\n';
}