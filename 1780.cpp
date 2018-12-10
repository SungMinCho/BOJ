#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

#define MAXN 100002

int N;
int board[2200][2200];

int countnum[3]; // countnum[2] is countnuming -1

void f(int I, int J, int L) {
  bool allSame = true;
  int val = board[I][J];
  for(int i=I; i<I+L; i++) {
    for(int j=J; j<J+L; j++) {
      if(val != board[i][j]) {
        allSame = false;
        break;
      }
    }
    if(!allSame) break;
  }

  if(allSame) {
    countnum[(val+3)%3]++;
  } else {
    int l = L / 3;
    for(int i=0; i<3; i++) {
      for(int j=0; j<3; j++) {
        f(I + i*l, J + j*l, l);
      }
    }
  }
}

int main() {
  scanf("%d", &N);

  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      scanf("%d", &board[i][j]);
    }
  }

  f(0,0,N);

  printf("%d\n%d\n%d\n", countnum[2],countnum[0],countnum[1]);
}
