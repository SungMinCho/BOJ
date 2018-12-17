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

using namespace std;

struct Pos {
  Pos(int r, int c) : row(r), col(c) {}
  Pos() : Pos(0,0) {}
  int row, col;
};

bool canAttack(const Pos& a, const Pos& b) {
  if(a.row == b.row) return true;
  if(a.col == b.col) return true;
  if(abs(a.row-b.row) == abs(a.col-b.col)) return true;
  return false;
}

bool board[16][16];
int N;
int ans;

void backtrack(int row, vector<Pos>& queens) {
  if(row==N+1) {
    ans++;
    return;
  }
  for(int i=1; i<=N; i++) {
    Pos queen(row, i);
    bool dont = false;
    for(auto q : queens) {
      if(canAttack(q, queen)) {
        dont = true;
        break;
      }
    }
    if(!dont) {
      queens.push_back(queen);
      backtrack(row+1, queens);
      queens.resize(queens.size()-1);
    }
  }
}

int main() {
  scanf("%d", &N);
  for(int i=1; i<=N; i++) {
    vector<Pos> queens(1, Pos(1, i));
    backtrack(2,queens);
  }
  printf("%d\n", ans);
}