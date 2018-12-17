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

struct Dict {
  map<vector<int>, long double> m;
  Dict() {}
  bool exists(vector<int>& v) {
    return (m.find(v) != m.end());
  }
  long double get(vector<int>& v) {
    return m[v];
  }
  void save(vector<int>& v, long double d) {
    m[v] = d;
  }
};

// use indexing from 1
string cards[10][5]; // cards[group][ith from below]
Dict dict;

long double getD(vector<int>& top) {
  //cout << "getD ";
  //for_each(top.begin(), top.end(), [](int i){ cout << i << " "; });
  //cout << endl;
  if(all_of(top.begin(), top.end(), [](int i){ return i == 0; })) return 1.0;
  if(dict.exists(top)) return dict.get(top);

  int cnt = 0;
  long double ans = 0.0;
  for(int i=1; i<9; i++) {
    for(int j=i+1; j<=9; j++) {
      int ti = top[i];
      int tj = top[j];
      if(ti == 0 || tj == 0) continue;
      if(cards[i][ti][0] == cards[j][tj][0]) {
        cnt += 1;
        top[i] -= 1;
        top[j] -= 1;
        ans += getD(top);
        top[i] += 1;
        top[j] += 1;
      }
    }
  }
  if(cnt > 0) ans /= cnt;
  dict.save(top, ans);

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for(int group=1; group<=9; group++) {
    for(int i=1; i<=4; i++) {
      cin >> cards[group][i];
    }
  }

  vector<int> top = {0,4,4,4,4,4,4,4,4,4};
  cout << getD(top) << endl;
}