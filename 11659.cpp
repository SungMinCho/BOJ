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

int N, M;

struct ST {
  vector<ll> arr;
  vector<ll> sumArray;
  int len;
  ST(vector<ll>& a) : arr(move(a)) { 
    len = arr.size()-1;
    makeSum(1, 1, len); 
  }

  ll makeSum(int node, int coverFrom, int coverTo) {
    if(sumArray.size() <= node) sumArray.resize(node+1);
    if(coverFrom == coverTo) return sumArray[node] = arr[coverFrom];
    int mid = (coverFrom+coverTo)/2;
    return sumArray[node] = makeSum(node*2, coverFrom, mid) + makeSum(node*2+1, mid+1, coverTo);
  }

  ll sum(int from, int to) {
    return sum(1, 1, len, from, to);
  }

  ll sum(int node, int coverFrom, int coverTo, int from, int to) {
    if(from > coverTo || to < coverFrom) return 0;
    if(from <= coverFrom && to >= coverTo) return sumArray[node];
    int mid = (coverFrom + coverTo) / 2;
    return sum(node*2, coverFrom, mid, from, to) + sum(node*2+1, mid+1, coverTo, from, to);
  }

  void update(int at, ll val) {
    update(1, 1, len, at, val);
  }

  ll update(int node, int coverFrom, int coverTo, int at, int val) {
    if(at < coverFrom || at > coverTo) return sumArray[node];
    if(coverFrom == coverTo) {
      arr[at] = val;
      sumArray[node] = val;
      return val;
    }
    int mid = (coverFrom+coverTo)/2;
    return sumArray[node] = update(node*2, coverFrom, mid, at, val) + update(node*2+1, mid+1, coverTo, at, val);
  }

};

int main() {
  scanf("%d %d", &N, &M);
  vector<ll> arr(N+1);
  for(int i=1; i<=N; i++) {
    scanf("%lld", &arr[i]);
  }
  ST st(arr);
  for(int i=0; i<M; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%lld\n", st.sum(a, b));
  }
}