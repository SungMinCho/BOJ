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

inline int max(int a, int b) { return a > b ? a : b; }

void getPi(const string& s, vector<vector<int>>& pi) {
  int m = s.size();
  pi.resize(m, vector<int>(m, 0));
  for(int pre=0; pre<m; pre++) {
    int begin=1, match=0;
    while(pre + begin + match < m) {
      if(s[pre + match] == s[pre + begin + match]) {
        match++;
        pi[pre][begin+match-1] = match;
      }
      else {
        if(match==0) begin++;
        else {
          begin += match - pi[pre][match-1];
          match = pi[pre][match-1];
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  //cin.tie(NULL);
  vector<vector<int>> pi;
  string s;
  getline(cin, s);
  getPi(s, pi);
  int ans = 0;
  for(auto v : pi) for(auto i : v) ans = max(ans, i);
  cout << ans << endl;
}
