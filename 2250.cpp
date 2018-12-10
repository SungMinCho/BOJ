#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

#define MAXN 10005
#define NOPARENT 0
#define LEFT 1
#define RIGHT 2

int n;
int leftnode[MAXN];
int rightnode[MAXN];
int parent[MAXN];
int treesize[MAXN];
vector<int> minX; // of the level
vector<int> maxX; // of the level
int maxLevel;

int min(int a, int b) { return a<b ? a : b; }
int max(int a, int b) { return a>b ? a : b; }

int getTreeSize(int node) {
  if(node == -1) return 0;
  if(treesize[node] != -1) return treesize[node];
  return (treesize[node] = 
      1 + getTreeSize(leftnode[node]) + getTreeSize(rightnode[node]));
}

void giveX(int node, int level, int parentX, int parentAt) {
  if(node == -1) return;
  maxLevel = max(maxLevel, level);
  int X;
  if(parentAt == NOPARENT) {
    // this node is the root. give it X=0
    X = 0;
  } else if(parentAt == LEFT) {
    X = parentX + 1 + getTreeSize(leftnode[node]);
  } else { // at rightnode
    X = parentX - 1 - getTreeSize(rightnode[node]);
  }
  minX[level] = min(minX[level], X);
  maxX[level] = max(maxX[level], X);

  giveX(leftnode[node], level+1, X, RIGHT);
  giveX(rightnode[node], level+1, X, LEFT);
}

int main() {
  scanf("%d", &n);
  
  for(int i=0; i<n; i++) {
    int a;
    scanf("%d", &a);
    scanf("%d %d", &leftnode[a], &rightnode[a]);
    parent[leftnode[a]] = a;
    parent[rightnode[a]] = a;
  }

  int root;
  for(int i=1; i<=n; i++) {
    if(parent[i] == 0) root = i;
    treesize[i] = -1;
  }

  minX.resize(n+1, INT_MAX);
  maxX.resize(n+1, INT_MIN);

  giveX(root, 1, 0, NOPARENT);

  int maxWidth = 1;
  int maxWidthLevel = 1;
  for(int level=2; level<=maxLevel; level++) {
    if(minX[level] != INT_MAX &&
       maxX[level] != INT_MIN &&
       maxX[level] - minX[level] + 1 > maxWidth) {
      maxWidth = maxX[level]-minX[level]+1;
      maxWidthLevel = level;
    }
  }

  printf("%d %d\n", maxWidthLevel, maxWidth);
}
