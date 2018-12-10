#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

#define MAXN 100005

int parent[MAXN];
int leftroot[MAXN];
int rightroot[MAXN];

int inorder[MAXN];
int postorder[MAXN];
int node2inorderindex[MAXN];
int n;
int posthead;

int maketree(int inlo, int inhi, int parentnode) {
  if(inlo > inhi) return 0;
  int root = postorder[posthead--];
  int rootin = node2inorderindex[root];
  if(inlo == inhi) {
    return root;
  }

  parent[root] = parentnode;
  rightroot[root] = maketree(rootin+1, inhi, root);
  leftroot[root] = maketree(inlo, rootin-1, root);

  return root;
}

void preorder(int root) {
  if(root == 0) return;
  printf("%d ", root);
  preorder(leftroot[root]);
  preorder(rightroot[root]);
}

int main() {
  scanf("%d", &n);
  for(int i=1; i<=n; i++) {
    scanf("%d", &inorder[i]);
    node2inorderindex[inorder[i]] = i;
  }
  for(int i=1; i<=n; i++) scanf("%d", &postorder[i]);

  posthead = n;
  maketree(1,n,0);
  preorder(postorder[n]);
  cout << endl;
}
