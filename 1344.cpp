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
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;

long double pA, pB;
long double P;

int c[20][20];
inline int C(int a, int b) {
  if(a == 0) return 1;
  if(b == 0 || b == a) return 1;
  if(c[a][b] != -1) return c[a][b];

  return c[a][b] = C(a-1,b) + C(a-1,b-1);
}

bool isPrime(int x) {
  if(x < 2) return false;
  for(int d=2; d*d<=x; d++) {
    if(x % d == 0) return false;
  }
  return true;
}

int main() {
  for(int i=0; i<20; i++) for(int j=0; j<20; j++) c[i][j] = -1;
  scanf("%Lf %Lf", &pA, &pB);
  pA /= 100.0;
  pB /= 100.0;

  for(int goalA = 0; goalA <= 18; goalA++) {
    for(int goalB = 0; goalB <= 18; goalB++) {
      if(isPrime(goalA) || isPrime(goalB)) continue;
      int ca = C(18, goalA);
      int cb = C(18, goalB);
      P += pow(pA, goalA)*pow(1-pA,18-goalA)*ca * pow(pB,goalB)*pow(1-pB,18-goalB)*cb;
    }
  }

  printf("%Lf\n", 1.0-P);
}