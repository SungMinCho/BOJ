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

using namespace std;

int dir[100000];
int len;
int d[100001][5][5]; // d[from][left][right]

inline int cost(int from, int to) {
  if(from == 0) return 2;
  if(from == to) return 1;
  if(abs(from-to) == 2) return 4;
  return 3;
}

int main() {
  int i;
  while(true) {
    scanf("%d", &i);
    if(i==0) break;
    dir[++len] = i; // 1 ~ len
  }

  for(int from=len; from>=1; from--) {
    for(int left=0; left<=4; left++) {
      for(int right=0; right<=4; right++) {
        int nextdir = dir[from];
        int leftMoveCost = cost(left, nextdir);
        int rightMoveCost = cost(right, nextdir);
        if(left == nextdir) d[from][left][right] = 1 + d[from+1][left][right];
        else if(right == nextdir) d[from][left][right] = 1 + d[from+1][left][right];
        else d[from][left][right] = min(leftMoveCost + d[from+1][nextdir][right],
                                        rightMoveCost + d[from+1][left][nextdir]);
      }
    }
  }

  printf("%d\n", d[1][0][0]);
}