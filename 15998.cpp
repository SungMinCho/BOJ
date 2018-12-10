#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
  if(b>a) return gcd(b,a);
  if(b==0) return a;
  return gcd(b, a%b);
}

ll lehmer_gcd(ll a, ll b) {
    if(b>a) return gcd(b, a);
    if(b==0) return a;
    if(a%2==0 && b%2==0) return 2*gcd(a/2, b/2);
    if(a%2==0 && b%2==1) return gcd(a/2, b);
    if(a%2==1 && b%2==0) return gcd(a, b/2);
    return gcd((a-b)/2, b);
}

int main() {
  int N;
  scanf("%d", &N);
  ll money = 0;
  bool contradiction = false;
  ll g = -1;
  ll M_min = -99999999;
  for(int i=0; i<N; i++) {
    ll a, b;
    scanf("%lld %lld", &a, &b);
    if(contradiction) break;
    if(a>0) {
      if(money + a != b) contradiction = true;
      else money = b;
    } else {
      a = -a;
      if(money > a) {
        if(money-a != b) contradiction = true;
        else money = b;
      } else {
        if(g==-1) g = a+b-money;
        g = gcd(g, a+b-money);
        if(b > M_min) M_min = b;
        if(g <= M_min) contradiction = true;
        money = b;
      }
    }
  }

  if(contradiction) printf("-1\n");
  else if(g == -1) printf("1\n");
  else printf("%lld\n", g);

  return 0;
}
