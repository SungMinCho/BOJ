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

int N;

struct Mat {
  vector<vector<int>> m;
  Mat(vector<vector<int>>& m_) : m(m_) {}
};

Mat mult(Mat& a, Mat& b) {
  vector<vector<int>> m(N, vector<int>(N,0));
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      for(int k=0; k<N; k++) {
        m[i][j] += a.m[i][k] * b.m[k][j];
        m[i][j] %= 1000;
      }
    }
  }
  return Mat(m);
}

Mat pow(Mat& a, ll n) {
  if(n==1) return a;
  Mat m = pow(a, n/2);
  Mat mm = mult(m,m);
  if(n%2==0) return mm;
  return mult(mm,a);
}

int main() {
  ll n;
  scanf("%d %lld", &N, &n);
  vector<vector<int>> m(N, vector<int>(N,0));
  for(int i=0; i<N; i++) for(int j=0; j<N; j++) scanf("%d", &m[i][j]);
  for(int i=0; i<N; i++) for(int j=0; j<N; j++) m[i][j] %= 1000;
  Mat a(m);
  Mat ans = pow(a, n);
  for(auto& row : ans.m) {
    for(auto x : row) printf("%d ", x);
    printf("\n");
  }
}