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

int N;
int d[101][10][1024]; // d[length][startswith][visited]

int getD(int length, int startswith, int visited) {
  if(d[length][startswith][visited] != -1) return d[length][startswith][visited];
  if(length == 1) {
    if(1023 == (visited | (1<<startswith))) return (d[length][startswith][visited] = 1);
    return (d[length][startswith][visited] = 0);
  }
  int ans = 0;
  for(int s = startswith-1; s <= startswith+1; s+=2) {
    if(s < 0 || s > 9) continue;
    ans = (ans + getD(length-1, s, visited|(1<<startswith))) % 1000000000;
  }
  return (d[length][startswith][visited] = ans);
}

int main() {
  scanf("%d", &N);

  memset(d, -1, sizeof(d[0][0][0])*101*10*1024);

  int ans = 0;
  for(int i=1; i<=9; i++) ans = (ans + getD(N, i, 0)) % 1000000000;
  
  printf("%d\n", ans);
}