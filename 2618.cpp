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

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }

struct Pos {
  int x, y;
};

inline int dist(const Pos& a, const Pos& b) {
  return abs(a.x-b.x) + abs(a.y-b.y);
}
int N, W;
int totalDist;
vector<int> record;
vector<Pos> calls;
int Dmove[1001][1001];
int Ddist[1001][1001];
Pos origP1;
Pos origP2;

inline Pos getPos(int police, int at) {
  if(at > 0) return calls[at];
  else if(police == 1) return origP1;
  else return origP2;
}

inline int getDdist(int p1, int p2);

inline int getDmove(int p1, int p2) {
  if(max(p1, p2) == W) return 0;
  if(Dmove[p1][p2] != 0) return Dmove[p1][p2];

  int nextCall = max(p1,p2) + 1;
  Pos& nextPos = calls[nextCall];

  int d1 = dist(nextPos, getPos(1, p1)) + getDdist(nextCall, p2);
  int d2 = dist(nextPos, getPos(2, p2)) + getDdist(p1, nextCall);

  if(d1 < d2) {
    Dmove[p1][p2] = 1;
    Ddist[p1][p2] = d1;
  } else {
    Dmove[p1][p2] = 2;
    Ddist[p1][p2] = d2;
  }
  return Dmove[p1][p2];
}

inline int getDdist(int p1, int p2) {
  if(max(p1, p2) == W) return 0;
  if(Dmove[p1][p2] != 0) return Ddist[p1][p2];
  getDmove(p1, p2);
  return Ddist[p1][p2];
}

int main() {
  scanf("%d %d", &N, &W);
  origP1 = {.x=1,.y=1};
  origP2 = {.x=N,.y=N};
  calls.resize(W+1);
  for(int i=1; i<=W; i++) {
    scanf("%d %d", &calls[i].x, &calls[i].y);
  }

  int p1 = 0, p2 = 0;
  printf("%d\n", getDdist(0,0));
  for(int call=1; call<=W; call++) {
    if(getDmove(p1, p2) == 1) {
      record.push_back(1);
      p1 = call;
    } else {
      record.push_back(2);
      p2 = call;
    }
  }

  for(auto r : record) printf("%d\n", r);
}