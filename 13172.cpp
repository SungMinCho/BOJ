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

using namespace std;
typedef long long ll;

ll MOD = 1000000007;

int N;
ll ans;

ll gcd(ll a, ll b){
  if(b==0) return a;
  return gcd(b, a%b);
}

ll pow(ll a, ll n) {
  if(n==0) return 1;
  if(n==1) return a;
  ll m = pow(a,n/2);
  ll mm = (m*m)%MOD;
  if(n%2==0) return mm;
  else return (mm*a)%MOD;
}

int main() {
  scanf("%d", &N);
  for(int i=0; i<N; i++) {
    ll a, b;
    scanf("%lld %lld", &a, &b);
    ll g = gcd(a,b);
    a /= g; b /= g;
    ans = (ans+b*pow(a,MOD-2))%MOD;
  }
  printf("%lld\n", ans);
}