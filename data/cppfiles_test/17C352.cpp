#include <bits/stdc++.h>
using namespace std;
bool check(vector<vector<int>> &ranks, int i, int j) {
  int c = 0;
  for (int k = 0; k < 5; k++) {
    if (ranks[i][k] < ranks[j][k]) {
      c++;
    }
  }
  return (c >= 3);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<vector<int>> ranks(n, vector<int>(5, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        cin >> ranks[i][j];
      }
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
      if (check(ranks, i, ans)) {
        ans = i;
      }
    }
    for (int i = 0; i < n; i++) {
      if (i == ans) {
        continue;
      }
      if (check(ranks, i, ans)) {
        ans = -1;
        break;
      }
    }
    cout << (ans == -1 ? ans : ans + 1) << endl;
  }
}
