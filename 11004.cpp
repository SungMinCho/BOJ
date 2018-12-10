#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

#define MAXN 100002

int N, K;
int a[5000005];

int main() {
  scanf("%d %d", &N, &K);

  for(int i=0; i<N; i++) scanf("%d", &a[i]);
  sort(a, a+N);

  printf("%d\n", a[K-1]);
}
