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
  for(int i=1, j=0; i < m; i++) {
    while(j && s[i] != s[j]) j = pi[j-1];
    if(s[i] == s[j]) {
      pi[i] = ++j;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  while(true) {
    string s;
    vector<int> pi;
    getline(cin, s);
    if(s == ".") break;
    getPi(s, pi);
    int m = s.size();
    int p = pi[m-1];
    if(p < m/2) cout << "1\n";
    else if( (p+p-m) % (m-p) ) cout << "1\n";
    else cout << m / (m-p) << "\n";
  }
}
