#include <stdio.h>
#include <tuple>
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
#include <cstring>
#include <cmath>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
  if(b==0) return a;
  return gcd(b, a%b);
}

int N, M;
ll d[21][21]; // d[boxes][openable]

int main() {

  cin >> N >> M;

  for(int j=0; j<=N; j++) d[0][j] = 1;

  for(int i=1; i<=N; i++) {
    d[i][0] = 0;
    for(int j=1; j<=N; j++) {
      d[i][j] = d[i-1][j-1] + (i-1)*d[i-1][j];
    }
  }

  ll a = d[N][M];
  ll b = d[N][N];
  ll g = gcd(a,b);
  cout << a/g << "/" << b/g << endl;
}