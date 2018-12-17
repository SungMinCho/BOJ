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

struct Interval{ 
  int start, end;
};
struct Comp {
  inline bool operator()(const Interval& a, const Interval& b) { 
    if(a.end != b.end) return a.end < b.end;
    return a.start < b.start;
  }
};

vector<Interval> meetings;
int N;

int main() {
  scanf("%d", &N);
  meetings.resize(N);
  for(int i=0; i<N; i++) {
    scanf("%d %d", &meetings[i].start, &meetings[i].end);
  }
  sort(meetings.begin(), meetings.end(), Comp());

  int cnt=0;
  int end = -1;
  for(auto& meeting : meetings) {
    if(meeting.start >= end) {
      cnt++;
      end = meeting.end;
    }
  }

  printf("%d\n", cnt);
}