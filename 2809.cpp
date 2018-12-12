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

int n, m;
string s;
vector<int> suffixArray, lcp, changeArray;
vector<string> tiles;

void getSuffixArray() {
  int n = s.size();
  suffixArray.resize(n, 0);
  vector<int> group(n+1, 0);
  for(int i=0; i<n; i++) suffixArray[i] = i;
  for(int i=0; i<n; i++) group[i] = s[i];
  group[n] = -1;
  int t = 1;
  while(t < n) {
    Comp comp(group, t);
    sort(suffixArray.begin(), suffixArray.end(), comp);
    t *= 2;
    if(t >= n) break;

    vector<int> newGroup(n+1);
    newGroup[n] = -1;
    newGroup[suffixArray[0]] = 0;
    for(int i=1; i<n; i++) {
      if(comp(suffixArray[i-1],suffixArray[i])) newGroup[suffixArray[i]] = newGroup[suffixArray[i-1]] + 1; //different
      else newGroup[suffixArray[i]] = newGroup[suffixArray[i-1]]; // same
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

void getLCP() {
  Saver saver;
  int n = s.size();
  lcp.resize(n, 0);
  for(int i=1; i<n; i++) {
    int common = 0;
    int shorter = max(suffixArray[i-1], suffixArray[i]);
    int longer = min(suffixArray[i-1], suffixArray[i]);
    while(s[suffixArray[i-1] + common] == s[suffixArray[i] + common] &&
          shorter + common < n && !saver.exists(shorter+common, longer+common)) common++;
    if(saver.exists(shorter+common, longer+common)) lcp[i] = common + saver.get(shorter+common, longer+common);
    else lcp[i] = common;
    saver.save(shorter, longer, lcp[i]);
  }
}

int binSearch(int lo, int hi, const string& tile) {
  if(lo > hi) return -1;
  if(lo == hi) {
    const string& ss = s.substr(suffixArray[lo], tile.size());
    if(tile.compare(ss) == 0) return lo;
    return -1;
  }

  int mid = (lo+hi)/2;
  const string& ss = s.substr(suffixArray[mid], tile.size());
  int compare = tile.compare(ss);
  if(compare < 0) return binSearch(lo, mid-1, tile);
  else if(compare == 0) return binSearch(lo, mid, tile);
  else return binSearch(mid+1, hi, tile);
}

int getFirstPos(const string& tile) {
  return binSearch(0, n-1, tile);
}

void mark(int start, int length) {
  changeArray[start]++;
  changeArray[start+length]--;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> s >> m;
  tiles.resize(m);
  for(int i=0; i<m; i++) {
    cin >> tiles[i];  
  }

  getSuffixArray();
  getLCP();

  changeArray.resize(n+1, 0);

  for(auto& tile : tiles) {
    int i = getFirstPos(tile);
    if(i == -1) continue;
    int length = tile.size();
    mark(suffixArray[i], length);
    int j = i+1;
    while(j < n && lcp[j] >= length) {
      mark(suffixArray[j++], length);
    }
  }

  int ans = 0;
  if(changeArray[0] == 0) ans++;
  for(int i=1; i<n; i++) {
    changeArray[i] += changeArray[i-1];
    if(changeArray[i] == 0) ans++;
  }

  cout << ans << '\n';

}
