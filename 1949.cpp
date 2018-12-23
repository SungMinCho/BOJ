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
#include <assert.h>

using namespace std;

int N;
int w[10001];
vector<vector<int>> adj;
int INF = 987654321;

struct Node {
  int num, value;
  vector<Node*> children;
  int ans[2][2];
  Node(int n, int v) : num(n), value(v) {
    ans[0][0] = ans[0][1] = ans[1][0] = ans[1][1] = -1;
  }

  int bestValue(int colorthis, int colorparent) {
    if(ans[colorthis][colorparent] != -1) return ans[colorthis][colorparent];
    int ret;
    if(colorthis) {
      if(colorparent) assert(false); // invalid
      else {
        ret = value;
        for(auto c : children) ret += c->bestValue(0,1);
      }
    } else {
      if(colorparent) {
        ret = 0;
        for(auto c : children) ret += max(c->bestValue(1,0), c->bestValue(0,0));
      } else {
        ret = 0;
        int cntzerochild = 0;
        int leastdiff = INF;
        for(auto c : children) {
          int zerochild = c->bestValue(0,0);
          int onechild = c->bestValue(1,0);
          leastdiff = min(leastdiff, onechild-zerochild);
          if(zerochild > onechild) {
            cntzerochild++;
            ret += zerochild;
          } else ret += onechild;
        }

        if(cntzerochild < children.size() || children.size() == 0) {
          return ret;
        } else {
          return ret + leastdiff;
        }
      }
    }
    return ans[colorthis][colorparent] = ret;
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
  printf("%d\n", max(root->bestValue(0,0), root->bestValue(1,0)));
}