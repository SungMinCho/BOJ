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

#define MAXN 5000001

int N, L;
int a[MAXN];

inline int min(int a, int b) { return a < b ? a : b; }

inline int getA(int i) {
  if(0<= i && i < N) return a[i];
  return INT_MAX;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> N >> L;
  for(int i=0; i<N; i++) {
    cin >> a[i];
  }

  int begin = -(L-1);
  int cnt = 0;
  while(cnt < N) {
    vector<int> cut(2*L-1);
    cut[L-1] = a[begin+L-1];
    for(int i=L-2; i>=0; i--) {
      cut[i] = min(cut[i+1], getA(begin+i));
    }
    for(int i=L; i<2*L-1; i++) {
      cut[i] = min(cut[i-1], getA(begin+i));
    }

    for(int i=0; i<L; i++) {
      cout << min(cut[i], cut[i+L-1]) << ' ';
      cnt++;
      if(cnt == N) break;
    }
    begin += L;
  }

  cout << '\n';
}