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
#include <utility>
#include <deque>

using namespace std;
typedef long long ll;

int N;
int w[10001];
vector<vector<int>> adj;
vector<bool> globalColor;

struct Node {
  int num, value;
  vector<Node*> children;
  map<int, bool> bestChildrenColorWhenColorThisNode;
  map<int, bool> bestChildrenColorWhenDontColorThisNode;
  int bestValueWhenColorThisNodeAns;
  int bestValueWhenDontColorThisNodeAns;
  Node(int n, int v) : num(n), value(v) {
    bestValueWhenColorThisNodeAns = -1;
    bestValueWhenDontColorThisNodeAns = -1;
  }

  int bestValueWhenColorThisNode() {
    if(bestValueWhenColorThisNodeAns != -1) return bestValueWhenColorThisNodeAns;
    int ans = value;
    for(auto c : children) {
      ans += c->bestValueWhenDontColorThisNode();
      bestChildrenColorWhenColorThisNode[c->num] = false;
    }
    return bestValueWhenColorThisNodeAns = ans;
  }

  int bestValueWhenDontColorThisNode() {
    if(bestValueWhenDontColorThisNodeAns != -1) return bestValueWhenDontColorThisNodeAns;
    int ans = 0;
    for(auto c : children) {
      int c1 = c->bestValueWhenColorThisNode();
      int c0 = c->bestValueWhenDontColorThisNode();
      if(c0 > c1) {
        bestChildrenColorWhenDontColorThisNode[c->num] = false;
        ans += c0;
      } else {
        bestChildrenColorWhenDontColorThisNode[c->num] = true;
        ans += c1;
      }
    }
    return bestValueWhenDontColorThisNodeAns = ans;
  }

  void colorGlobal(bool colorThisNode) {
    map<int, bool>& m = bestChildrenColorWhenColorThisNode;
    if(!colorThisNode) m = bestChildrenColorWhenDontColorThisNode;
    for(auto& c : children) {
      globalColor[c->num] = m[c->num];
      c->colorGlobal(m[c->num]);
    }
  }
};

Node* make_tree(int root, int parent) {
  Node* node = new Node(root, w[root]);
  for(auto& there : adj[root]) {
    if(there == parent) continue;
    node->children.push_back(make_tree(there, root));
  }
  return node;
}

int main() {
  scanf("%d", &N);
  for(int i=1; i<=N; i++) scanf("%d", &w[i]);
  int a, b;
  adj.resize(N+1);
  while(scanf("%d %d", &a, &b) == 2) {
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  Node* root = make_tree(1,0);
  globalColor.resize(N+1);
  int ans1 = root->bestValueWhenColorThisNode();
  int ans2 = root->bestValueWhenDontColorThisNode();
  if(ans1 > ans2) {
    printf("%d\n", ans1);
    root->colorGlobal(true);
    globalColor[1] = true;
  } else {
    printf("%d\n", ans2);
    root->colorGlobal(false);
    globalColor[1] = false;
  }
  for(int i=1; i<=N; i++) if(globalColor[i]) printf("%d ", i);
  printf("\n");
}