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
#include <stdlib.h>

using namespace std;

typedef long long ll;

int n, m;
vector<int> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  v.resize(n); 
  for(int i=0; i<n; i++) cin >> v[i];
  sort(v.begin(), v.end());

  cin >> m;
  for(int i=0; i<m; i++) {
    int x;
    cin >> x;
    if(binary_search(v.begin(), v.end(), x)) cout << "1 ";
    else cout << "0 ";
  }

  cout << '\n';
}