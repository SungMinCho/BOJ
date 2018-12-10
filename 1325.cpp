#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

#define MAXN 10005
#define MAXM 100005

int N, M;
vector<vector<int>> adj;
vector<int> sccId;
vector<int> discovered;
stack<int> subtree;
vector<int> sccSize;
//vector<vector<int>> sccInts;
vector<int> sccCanHack;
vector<vector<int>> sccAdj;
vector<bool> viz;
int sccIdCnt;
int timeCnt;

inline int min(int a, int b) { return a < b ? a : b; }

int scc(int here) {
  int ret = discovered[here] = ++timeCnt;
  subtree.push(here);

  for(auto there : adj[here]) {
    if(discovered[there] == -1) {
      ret = min(ret, scc(there));
    }
    else if(sccId[there] == -1) {
      ret = min(ret, discovered[there]);
    }
  }

  if(ret == discovered[here]) {
    sccIdCnt++;
    sccSize.resize(sccSize.size()+1);
    //sccInts.resize(sccInts.size()+1);
    sccCanHack.resize(sccCanHack.size()+1);
    int sz = 0;
    while(true) {
      sz++;
      int t = subtree.top();
      subtree.pop();
      sccId[t] = sccIdCnt;
      //sccInts[sccIdCnt].push_back(t);
      if(t == here) break;
    }
    sccSize[sccIdCnt] = sz;
  }

  return ret;
}

int getCanHack(int s) {
  if(viz[s]) return 0;
  viz[s] = true;
  int ret = sccSize[s];
  for(auto a : sccAdj[s]) {
    ret += getCanHack(a);
  }
  return ret;
}

int main() {
  scanf("%d %d", &N, &M);

  adj.resize(N+1);
  sccId.resize(N+1, -1);
  discovered.resize(N+1, -1);
  sccSize.resize(1);
  //sccInts.resize(1);

  for(int i=0; i<M; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    adj[b].push_back(a);
  }

  for(int i=1; i<=N; i++) if(discovered[i] == -1) scc(i); 

  sccAdj.resize(sccIdCnt+1);

  for(int i=1; i<=N; i++) {
    for(auto j : adj[i]) {
      if(sccId[i] != sccId[j]) {
        if(find(sccAdj[sccId[i]].begin(), sccAdj[sccId[i]].end(), sccId[j]) == sccAdj[sccId[i]].end())
        sccAdj[sccId[i]].push_back(sccId[j]);
      }
    }
  }

  sccCanHack.resize(sccIdCnt+1);

  for(int s=1; s<=sccIdCnt; s++) {
    viz.clear();
    viz.resize(sccIdCnt+1, false);
    sccCanHack[s] = getCanHack(s);
  }

  int max_hack = *max_element(sccCanHack.begin()+1, sccCanHack.end());
  vector<int> ans;
  for(int i=1; i<=N; i++) if(sccCanHack[sccId[i]] == max_hack) ans.push_back(i);
  /*
  for(int s = 1; s <= sccIdCnt; s++) {
    if(sccCanHack[s] == max_hack) {
      for(auto i : sccInts[s]) ans.push_back(i);
    }
  }
  */

  sort(ans.begin(), ans.end());
  for(auto a : ans) cout << a << ' ';
  cout << endl;
  return 0;
}

