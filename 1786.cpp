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

void getPi(const string& s, vector<int>& pi) {
  int m = s.size();
  pi.resize(m, 0);
  for(int i=1, j=0; i<m; i++) {
    while(j && s[i] != s[j]) j = pi[j-1];
    if(s[i] == s[j]) {
      pi[i] = ++j;
    }
  }
}

void KMP(const string& s, const string& ss, vector<int>& ret) {
  int n = s.size();
  int m = ss.size();
  vector<int> pi;
  getPi(ss, pi);

  for(int i=0, j=0; i<n; i++) {
    while(j && s[i] != ss[j]) j = pi[j-1];
    if(s[i] == ss[j]) {
      j++;
      if(j==m) {
        ret.push_back(i-j+1);
        j = pi[j-1];
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);

  string s, ss;
  getline(cin, s);
  getline(cin, ss);

  vector<int> ret;
  KMP(s, ss, ret);

  cout << ret.size() << '\n';
  for(auto r : ret) cout << r+1 << '\n';
}
