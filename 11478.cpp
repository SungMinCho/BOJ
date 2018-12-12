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

struct Comp {
  const vector<int>& group;
  int t;
  Comp(const vector<int>& group_, int t_) : group(group_), t(t_) {}

  inline bool operator()(int a, int b) {
    if(group[a] != group[b]) return group[a] < group[b];
    return group[a+t] < group[b+t];
  }
};

void getSuffixArray(const string& s, vector<int>& v) {
  int n = s.size();
  v.resize(n, 0);
  vector<int> group(n+1, 0);
  for(int i=0; i<n; i++) v[i] = i;
  for(int i=0; i<n; i++) group[i] = s[i];
  group[n] = -1;
  int t = 1;
  while(t < n) {
    Comp comp(group, t);
    sort(v.begin(), v.end(), comp);
    t *= 2;
    if(t >= n) break;

    vector<int> newGroup(n+1);
    newGroup[n] = -1;
    newGroup[v[0]] = 0;
    for(int i=1; i<n; i++) {
      if(comp(v[i-1],v[i])) newGroup[v[i]] = newGroup[v[i-1]] + 1; //different
      else newGroup[v[i]] = newGroup[v[i-1]]; // same
    }
    group = newGroup;
  }
}

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }

struct Saver {
  map<pair<int,int>, int> m;
  Saver() {}
  
  void save(int i, int j, int val) {
    m[{i,j}] = val;
  }
  int get(int i, int j) {
    return m[{i,j}];
  }
  bool exists(int i, int j) {
    return m.find({i,j}) != m.end();
  }
};

void getLCP(const string& s, const vector<int>& suffix, vector<int>& lcp) {
  Saver saver;
  int n = s.size();
  lcp.resize(n, 0);
  for(int i=1; i<n; i++) {
    int common = 0;
    int shorter = max(suffix[i-1], suffix[i]);
    int longer = min(suffix[i-1], suffix[i]);
    while(s[suffix[i-1] + common] == s[suffix[i] + common] &&
          shorter + common < n && !saver.exists(shorter+common, longer+common)) common++;
    if(saver.exists(shorter+common, longer+common)) lcp[i] = common + saver.get(shorter+common, longer+common);
    else lcp[i] = common;
    saver.save(shorter, longer, lcp[i]);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  string s;
  getline(cin, s);

  vector<int> suffixArray;
  getSuffixArray(s, suffixArray);

  vector<int> lcp;
  getLCP(s, suffixArray, lcp);

  int ans = 0;
  int n = s.size();
  for(int i=0; i<n; i++) {
    ans += (n-suffixArray[i]) - lcp[i];
  }
  cout << ans << '\n';
}
