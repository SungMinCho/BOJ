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

int K;
vector<int> edges;
vector<int> pow2;

inline int max(int a, int b) { return a > b ? a : b; }

int makeEqual(int root) {
  int left = root*2+1;
  int right = left+1;
  if(left > pow2[K+1] - 2) return 0;

  int leftPath = makeEqual(left);
  int rightPath = makeEqual(right);
  int path = max(leftPath + edges[left], rightPath + edges[right]);
  edges[left] += (path - leftPath - edges[left]);
  edges[right] += (path - rightPath - edges[right]);

  return path;
}

int main() {
  pow2.resize(22);
  pow2[0] = 1;
  for(int i=1; i<22; i++) pow2[i] = pow2[i-1] * 2;

  scanf("%d", &K);
  edges.resize(pow2[K+1]-1);
  edges[0] = 0;
  for(int i=1; i < pow2[K+1]-1; i++) {
    scanf("%d", &edges[i]);
  }

  makeEqual(0);

  int sum = 0;
  for(auto e : edges) sum += e;
  printf("%d\n", sum);
}