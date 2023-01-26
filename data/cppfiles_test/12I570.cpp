#include <bits/stdc++.h>
using namespace std;
const long long INF = 2e9 + 9;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m, k;
    cin >> n >> m >> k;
    int grid[n + 2][m + 2];
    memset(grid, 0, sizeof grid);
    while (k > 0) {
      long long kantes = k;
      for (long long i = 0; i < (n); ++i) {
        for (long long j = 0; j < (m); ++j) {
          if (j < m - 1 && grid[i][j] == 0 && grid[i][j + 1] == 0 && k > 0) {
            grid[i][j] = 1;
            grid[i][j + 1] = 1;
            k--;
            break;
          }
        }
      }
      if (k == kantes) break;
    }
    for (long long i = 0; i < (n); ++i) {
      for (long long j = 0; j < (m); ++j) {
        if (i < n - 1 && grid[i][j] == 0 && grid[i + 1][j] == 0) {
          grid[i][j] = 1;
          grid[i + 1][j] = 1;
        }
      }
    }
    bool can = true;
    for (long long i = 0; i < (n); ++i)
      for (long long j = 0; j < (m); ++j)
        if (grid[i][j] == 0) can = false;
    if (can && k == 0)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
