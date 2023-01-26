#include <bits/stdc++.h>
using namespace std;
pair<int, int> ranks[5][50000];
bool cmp(pair<int, int>& a, pair<int, int>& b) { return a.second < b.second; }
int solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      int r;
      cin >> r;
      ranks[j][i] = {r, i};
    }
  }
  int winner = 0;
  for (int i = 1; i < n; i++) {
    int win_count = 0;
    for (int j = 0; j < 5; j++) {
      win_count += (ranks[j][winner] < ranks[j][i]);
    }
    if (win_count < 3) winner = i;
  }
  for (int i = 0; i < n; i++) {
    if (winner == i) continue;
    int win_count = 0;
    for (int j = 0; j < 5; j++) {
      win_count += (ranks[j][winner] < ranks[j][i]);
    }
    if (win_count < 3) return -1;
  }
  return winner + 1;
}
int main() {
  int testCase;
  cin >> testCase;
  while (testCase--) {
    cout << solve() << '\n';
  }
}
