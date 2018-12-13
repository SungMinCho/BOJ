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

vector<int> pre;

void pre2post(int lo, int hi) {
  if(lo > hi) return;
  if(lo == hi) { printf("%d\n", pre[lo]); return; }
  int root = pre[lo];
  int left = lo+1;
  while(left <= hi && pre[left] < root) left++;

  pre2post(lo+1, left-1);
  pre2post(left, hi);
  printf("%d\n", root);
}

int main() {
  int i;
  while(scanf("%d", &i) == 1) {
    pre.push_back(i);
  }

  pre2post(0, pre.size()-1);
}