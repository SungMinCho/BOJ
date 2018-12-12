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

ll n, k;

ll binSearch(ll lo, ll hi) {
  if(lo == hi) return lo;

  ll mid = (lo+hi)/2;

  ll cnt = 0;
  for(int i=1; i<=n; i++) {
    int less = mid / i;
    if(less > n) less = n;
    cnt += less;
  }
  if(cnt < k) return binSearch(mid+1, hi);
  else return binSearch(lo, mid);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> k;

  cout << binSearch(1, n*n) << '\n';
}