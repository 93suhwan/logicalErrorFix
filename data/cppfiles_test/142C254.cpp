#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O0")
#pragma GCC optimize("O1")
using namespace std;
int n, m;
bool check(int x, vector<vector<int>> vec) {
  vector<int> row(n, 0), col(m, 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vec[i][j] >= x) {
        row[i]++;
        col[j]++;
      }
    }
  }
  for (int i = 0; i < m; i++) {
    if (col[i] == 0) {
      return false;
    }
  }
  for (int i = 0; i < n; i++) {
    if (row[i] >= 2) {
      return true;
    }
  }
  return false;
}
void solve() {
  cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }
  int l = 0, r = 1e9 + 10;
  while (l + 1 < r) {
    int m = (l + r) / 2;
    if (check(m, grid)) {
      l = m;
    } else {
      r = m;
    }
  }
  cout << l << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
