#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int N,M;
  scanf("%d %d", &N, &M);
  char board[N][M];
  for(int i=0; i<N; i++) {
    scanf("%s", board[i]);
  }
  int ans = 1;
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      bool allsame = true;

      for(int io=-1; io<=1; io++) {
        for(int jo=-1; jo<=1; jo++) {
          if(io*jo != 0 || (io==0&&jo==0)) continue;
          if(i+io<0 || i+io>=N || j+jo<0 || j+jo>=M) continue;
          if(board[i][j] != board[i+io][j+jo]) allsame = false;
        }
      }

      if(allsame) ans = (ans*2) % 1000000007;
    }
  }

  printf("%d\n", ans);
}
