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

int n;
vector<int> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  v.resize(n);
  for(int i=0; i<n; i++) cin >> v[i];
  sort(v.begin(), v.end());
  int alo=0, amid=1, ahi=2;
  ll ans = llabs(v[0]+v[1]+v[2]);
  for(int middle = 1; middle < n-1; middle++) {
    int lo = 0, hi = n-1;
    while(lo < middle && middle < hi) {
      ll sum = v[lo] + v[middle] + v[hi];
      ll asum = llabs(sum);
      if(asum < ans) {
        ans = asum, alo = lo, amid = middle, ahi = hi;
      }
      if(sum < 0) lo++;
      else hi--;
    }
  }

  cout << v[alo] << ' ' << v[amid] << ' ' << v[ahi] << '\n';
}