#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

#define MAXN 100005

int n;
map<int, map<int, int>> weights;
vector<bool> viz;

struct Node {
  Node(int num_) : num(num_), heightSave(-1), minColor(18, INT_MAX) {}
  ~Node() { for(auto c : children) delete c; }
  int num;
  vector<Node*> children;
  vector<int> minColor;
  int getHeight();
  int heightSave;
  int getLongestLeaf2Leaf();
  int getLongestLeaf2LeafTotal();
  int minColoringWithThisNodeAs(int color);
};

int max(int a, int b) { return a>b ? a : b; }
int min(int a, int b) { return a<b ? a : b; }

int Node::getHeight() {
  if(heightSave != -1) return heightSave;
  if(children.size() == 0) return (heightSave = 0);

  int height = INT_MIN;
  for(auto c : children) {
    int w = weights[num][c->num];
    height = max(height, w + c->getHeight());
  }

  return (heightSave = height);
}

int Node::getLongestLeaf2Leaf() {
  if(children.size() < 2) return -1;

  vector<int> arms;
  for(auto c : children) {
    int w = weights[num][c->num];
    arms.push_back(w + c->getHeight());
  }
  sort(arms.begin(), arms.end());

  return arms[arms.size()-1] + arms[arms.size()-2];
}

int Node::getLongestLeaf2LeafTotal() {
  int ret = getLongestLeaf2Leaf();
  for(auto c : children) ret = max(ret, c->getLongestLeaf2LeafTotal());
  return ret;
}

int getDiameter(Node* node) {
  return max(node->getHeight(),
             node->getLongestLeaf2LeafTotal());
}

int Node::minColoringWithThisNodeAs(int color) {
  if(INT_MAX != minColor[color]) return minColor[color];
  int ans = color;
  for(auto c : children) {
    int cmin = INT_MAX;
    for(int i=1; i<=17; i++) {
      if(i == color) continue;
      cmin = min(cmin, c->minColoringWithThisNodeAs(i));
    }
    ans += cmin;
  }

  return (minColor[color] = ans);
}

Node* maketree(int root) {
  Node* node = new Node(root);
  viz[root] = true;
  for(auto kv : weights[root]) {
    int child = kv.first;
    if(!viz[child]) {
      Node* c = maketree(child);
      node->children.push_back(c);
    }
  }
  return node;
}

int main() {
  scanf("%d", &n);
  for(int i=1; i<n; i++) {
    int a, b, w;
    scanf("%d %d", &a, &b);
    weights[a][b] = 1;
    weights[b][a] = 1;
  }

  viz.resize(n+1);
  Node* root = maketree(1);

  int ans = INT_MAX;

  for(int i=1; i<=17; i++) ans = min(ans, root->minColoringWithThisNodeAs(i));
  printf("%d\n", ans);

  delete root;
  return 0;
}
