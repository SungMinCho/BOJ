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

int board[10][10];

struct Pos {
  int row, col;
  Pos(int r, int c) : row(r), col(c) {}
  Pos() : Pos(0,0) {}
};

vector<Pos> getUndone() {
  vector<Pos> ret;
  for(int i=1; i<=9; i++) for(int j=1; j<=9; j++) if(board[i][j] == 0) ret.push_back(Pos(i,j));
  return ret;
}

vector<int> getPossible(const Pos& pos) {
  vector<bool> possible(10, true);
  for(int i=1; i<=9; i++) possible[board[pos.row][i]] = false;
  for(int i=1; i<=9; i++) possible[board[i][pos.col]] = false;
  int startRow = (pos.row-1)/3*3 + 1;
  int startCol = (pos.col-1)/3*3 + 1;
  for(int i=0; i<3; i++) for(int j=0; j<3; j++) possible[board[i+startRow][j+startCol]] = false;
  vector<int> ret;
  for(int i=1; i<=9; i++) if(possible[i]) ret.push_back(i);
  return ret;
}

void printBoard() {
  for(int i=1; i<=9; i++) {
    for(int j=1; j<=9; j++) printf("%d ", board[i][j]);
    printf("\n");
  }
}

bool solve() {
  //printBoard(); cout << endl;
  //auto undone = getUndone();
  //if(undone.size() == 0) return true;
  for(int i=1; i<=9; i++) for(int j=1; j<=9; j++) {
    if(board[i][j] != 0) continue;
    Pos pos(i,j);
    auto possibleNumbers = getPossible(pos);
    for(auto possible : possibleNumbers) {
      board[pos.row][pos.col] = possible;
      if(solve()) return true;
      board[pos.row][pos.col] = 0;
    }
    return false;
  }
  return true;
}

int main() {
  for(int i=1; i<=9; i++) for(int j=1; j<=9; j++) scanf("%d", &board[i][j]);
  solve();
  printBoard();
}