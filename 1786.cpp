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

vector<int> getPi(const string& s, vector<int>& pi) {
  int m = s.size();
  pi.resize(m, 0);
  int begin=1, match=0;
  while(begin + match < m) {
    if(s[match] == s[begin+match]) {
      match++;
      pi[begin+match-1] = match;
    }
    else {
      if(match==0) begin++;
      else {
        begin += match - pi[match-1];
        match = pi[match-1];
      }
    }
  }
  return pi;
}

void getMatches(const string& s, const string& ss, vector<int>& ret) {
  int n = s.size();
  int m = ss.size();
  vector<int> pi;
  getPi(ss, pi);
  int begin = 0, match = 0;
  while(begin+match < n) {
    if(match < m && s[begin+match] == ss[match]) {
      match++;
      if(match == m) ret.push_back(begin);
    }
    else {
      if(match == 0) begin++;
      else {
        begin += match - pi[match-1];
        match = pi[match-1];
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  string s, ss;
  getline(cin, s);
  getline(cin, ss);
  vector<int> ret;
  getMatches(s, ss, ret);
  cout << ret.size() << '\n';
  for(auto r : ret) cout << r+1 << '\n';
}
