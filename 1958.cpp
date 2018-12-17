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

string s1, s2, s3;
int n1, n2, n3;
int LCS[101][101][101];

int main() {
  getline(cin, s1);
  getline(cin, s2);
  getline(cin, s3);
  n1 = s1.size(); n2 = s2.size(); n3 = s3.size();

  for(int i=1; i<=n1; i++) {
    for(int j=1; j<=n2; j++) {
      for(int k=1; k<=n3; k++) {
        if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1]) LCS[i][j][k] = LCS[i-1][j-1][k-1] + 1;
        if(s1[i-1] == s2[j-1])  {
          int kk = k-1;
          while(kk > 0 && s3[k-1] != s1[i-1]) kk--;
          if(kk != 0) LCS[i][j][k] = max(LCS[i][j][k], LCS[i-1][j-1][kk-1]+1);
        }

        if(s2[j-1] == s3[k-1])  {
          int ii = i-1;
          while(ii > 0 && s1[i-1] != s2[j-1]) ii--;
          if(ii != 0) LCS[i][j][k] = max(LCS[i][j][k], LCS[ii-1][j-1][k-1]+1);
        }

        if(s1[i-1] == s3[k-1])  {
          int jj = j-1;
          while(jj > 0 && s2[j-1] != s1[i-1]) jj--;
          if(jj != 0) LCS[i][j][k] = max(LCS[i][j][k], LCS[i-1][jj-1][k-1]+1);
        }

        LCS[i][j][k] = max(LCS[i][j][k], LCS[i-1][j-1][k-1]);
        LCS[i][j][k] = max(LCS[i][j][k], LCS[i-1][j][k]);
        LCS[i][j][k] = max(LCS[i][j][k], LCS[i][j][k-1]);
        LCS[i][j][k] = max(LCS[i][j][k], LCS[i][j-1][k]);

      }
    }
  }

  printf("%d\n", LCS[n1][n2][n3]);
}