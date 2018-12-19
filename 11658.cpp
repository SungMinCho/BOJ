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

int board[1025][1025];

struct ST {
  vector<int> arr;
  vector<int> sumArr;
  int len;
  ST() {}
  ST(vector<int>& a) : arr(move(a)) {
    len = arr.size()-1;
    makeSum(1, 1, len);
  }

  int makeSum(int node, int left, int right) {
    if(sumArr.size() <= node) sumArr.resize(node+1);
    if(left == right) return sumArr[node] = arr[left];
    int mid = (left+right)/2;
    return sumArr[node] = makeSum(node*2,left,mid) + makeSum(node*2+1,mid+1,right);
  }

  int sum(int from, int to) {
    return sum(1, 1, len, from, to);
  }

  int sum(int node, int left, int right, int from, int to) {
    if(from > right || to < left) return 0;
    if(from <= left && right <= to) return sumArr[node];
    int mid = (left+right)/2;
    return sum(node*2,left,mid,from,to) + sum(node*2+1,mid+1,right,from,to);
  }

  void update(int at, int dif) {
    update(1, 1, len, at, dif);
  }

  int update(int node, int left, int right, int at, int dif) {
    if(at < left || at > right) return sumArr[node];
    if(left==right) return sumArr[node] += dif;
    int mid = (left+right)/2;
    return sumArr[node] = update(node*2,left,mid,at,dif) + update(node*2+1,mid+1,right,at,dif);
  }
};

struct ST2 {
  vector<vector<int>> arr2;
  vector<ST> stArr;
  int rowlen, collen;

  ST2(vector<vector<int>>& a) : arr2(move(a)) {
    rowlen = arr2.size()-1;
    collen = arr2[0].size()-1;

    makeSum(1, 1, rowlen);
  }

  void makeSum(int node, int rowleft, int rowright) {
    if(stArr.size() <= node) stArr.resize(node+1);
    if(rowleft == rowright) {
      stArr[node] = ST(arr2[rowleft]);
      return;
    }
    int mid = (rowleft+rowright)/2;
    int leftnode = node*2;
    int rightnode = node*2+1;
    makeSum(leftnode, rowleft, mid);
    makeSum(rightnode, mid+1, rowright);
    merge(stArr[leftnode], stArr[rightnode], stArr[node]);
  }

  void merge(ST& a, ST& b, ST& r) {
    vector<int> row(collen+1);
    for(int i=1; i<=collen; i++) row[i] = a.arr[i] + b.arr[i];
    r = ST(row);
  }

  int sum(int rowfrom, int rowto, int colfrom, int colto) {
    return sum(1, 1, rowlen, rowfrom, rowto, colfrom, colto);
  }

  int sum(int node, int rowleft, int rowright, int rowfrom, int rowto, int colfrom, int colto) {
    if(rowfrom > rowright || rowto < rowleft) return 0;
    if(rowfrom <= rowleft && rowright <= rowto) return stArr[node].sum(colfrom, colto);
    int mid = (rowleft+rowright)/2;
    return sum(node*2, rowleft, mid, rowfrom, rowto, colfrom, colto) +
           sum(node*2+1, mid+1, rowright, rowfrom, rowto, colfrom, colto);
  }

  void update(int rowat, int colat, int dif) {
    update(1, 1, rowlen, rowat, colat, dif);
  }

  void update(int node, int rowleft, int rowright, int rowat, int colat, int dif) {
    if(rowat < rowleft || rowat > rowright) return;
    if(rowleft == rowright) {
      stArr[node].update(colat, dif);
      return;
    }

    int mid = (rowleft+rowright)/2;
    update(node*2,rowleft,mid,rowat,colat,dif);
    update(node*2+1,mid+1,rowright,rowat,colat,dif);
    stArr[node].update(colat, dif);
  }

};

int main() {
  int N, M;
  scanf("%d %d", &N, &M);
  vector<vector<int>> arr2(N+1, vector<int>(N+1));
  for(int i=1; i<=N; i++) for(int j=1; j<=N; j++) {scanf("%d", &arr2[i][j]); board[i][j] = arr2[i][j];}

  ST2 st2(arr2);

  for(int i=0; i<M; i++) {
    int w; scanf("%d", &w);
    if(w == 0) {
      int rowat, colat, val;
      scanf("%d %d %d", &rowat, &colat, &val);
      int diff = val-board[rowat][colat];
      board[rowat][colat] = val;
      st2.update(rowat, colat, diff);
    } else {
      int rowfrom, rowto, colfrom, colto;
      scanf("%d %d %d %d", &rowfrom, &colfrom, &rowto, &colto);
      printf("%d\n", st2.sum(rowfrom, rowto, colfrom, colto));
    }
  }
}