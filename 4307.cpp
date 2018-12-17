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

int T, L, N, More, Less;

int main() {
  scanf("%d", &T);
  for(int t=0; t<T; t++) {
    scanf("%d %d", &L, &N);
    More = Less = 0;
    for(int i=0; i<N; i++) {
      int at;
      scanf("%d", &at);
      More = max(More, max(at, L-at));
      Less = max(Less, min(at, L-at));
    }

    printf("%d %d\n", Less, More);
  }
}