#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

#define MAXN 100005
#define MOD 1000000007

typedef long long ll;

struct Node {
  Node(int n) : num(n), rootPathWeightSave(-1) {}
  ~Node() { for(auto c : children) delete c; }
  int num;
  vector<Node*> children;
  ll rootPathWeightSave;
  ll getRootPathWeight(); // sum of all path weights from any subtree node to root(this)
  ll getMiddlePathWeight(); // sum of all path weights from node->root->node (two different subtree)
};

int n;
map<int, map<int, int>> weights;
vector<bool> viz;
vector<Node*> nodes;


ll Node::getRootPathWeight() {
  if(rootPathWeightSave != -1) return rootPathWeightSave;
  if(children.size() == 0) return (rootPathWeightSave = 0);

  ll ans = 0;
  for(auto c : children) {
    ll w = weights[num][c->num];
    ans = (ans +  w + (w * c->getRootPathWeight()) % MOD) % MOD;
  }

  return (rootPathWeightSave = ans);
}

ll Node::getMiddlePathWeight() {
  if(children.size() < 2) return 0;
  ll ans = 0;
  ll psum = 0;
  for(auto c : children) {
    ll rp = c->getRootPathWeight();
    ll w = weights[num][c->num];
    ll p = (w+w*rp)%MOD;
    ans = (ans + psum*p) % MOD;
    psum = (psum + p) % MOD;
  }

  return ans;
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
  nodes.push_back(node);
  return node;
}

int main() {
  scanf("%d", &n);
  for(int i=1; i<=n-1; i++) {
    int a, b, w;
    scanf("%d %d %d", &a, &b, &w);
    weights[a][b] = w;
    weights[b][a] = w;
  }

  viz.resize(n+1);
  // root = 1
  Node* root = maketree(1);

  
  ll ans = 0;
  for(auto node : nodes) ans = (ans + node->getRootPathWeight()) % MOD;
  for(auto node : nodes) ans = (ans + node->getMiddlePathWeight()) % MOD;
  printf("%lld\n", ans);

  delete root;
  return 0;
}
