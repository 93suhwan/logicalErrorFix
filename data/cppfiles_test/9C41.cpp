#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int grid[1000 + 10][1000 + 10];
void solve() {
  int viscnt = 0;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
    }
  }
  for (int i = 0; i < k; i++) {
    int c;
    cin >> c;
    c--;
    int ans = 0;
    queue<pair<int, int>> qu;
    qu.push({0, c});
    while (!qu.empty()) {
      auto x = qu.front();
      qu.pop();
      int ii = x.first, jj = x.second;
      if (grid[ii][jj] == 1) {
        grid[ii][jj] = 2;
        qu.push({ii, jj + 1});
      } else if (grid[ii][jj] == 3) {
        grid[ii][jj] = 2;
        qu.push({ii, jj - 1});
      } else if (grid[ii][jj] == 2 && ii == n - 1) {
        ans = jj;
      } else {
        qu.push({ii + 1, jj});
      }
    }
    cout << ans + 1 << " ";
  }
}
void I_O() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  I_O();
  solve();
  return 0;
}
