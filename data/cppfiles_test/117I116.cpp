#include <bits/stdc++.h>
using namespace std;
int cases(1), tc;
const int64_t Mod = 1e9 + 7, Mod1 = 998244353;
const long long di[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
template <typename T>
T Power(T n, T k) {
  T x = 1;
  while (k) {
    if (k & 1) x *= n;
    n *= n;
    k >>= 1;
  }
  return x;
}
template <typename T>
long long Power(T n, T k, T M) {
  n %= M;
  T res = 1;
  while (k) {
    if (k & 1) res = res * n % M;
    n = n * n % M;
    k >>= 1;
  }
  return res;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << fixed << setprecision(15);
  for (cin >> tc; cases <= tc; cases++) {
    long long n, m;
    cin >> n >> m;
    vector<vector<char>> ans(n + 2, vector<char>(m + 2));
    char grid[n + 2][m + 2];
    memset(grid, '#', sizeof grid);
    vector<vector<long long>> cnt(n + 2, vector<long long>(m + 2, 0));
    for (long long i = 1; i <= n; i++) {
      for (long long j = 1; j <= m; j++) {
        cin >> grid[i][j];
        ans[i][j] = grid[i][j];
      }
    }
    for (long long i = 1; i <= n; i++) {
      for (long long j = 1; j <= m; j++) {
        if (grid[i][j] == '.') {
          for (long long run = 0; run < 4; run++) {
            long long x = i + di[run][0];
            long long y = j + di[run][1];
            cnt[i][j] += (grid[x][y] == '.');
          }
        }
      }
    }
    function<void(bool, long long, long long)> dfs = [&](bool root, long long i,
                                                         long long j) {
      if (root) {
        for (long long run = 0; run < 4; run++) {
          long long x = di[run][0] + i;
          long long y = di[run][1] + j;
          if (cnt[x][y] == 1) {
            ans[x][y] = '+';
            dfs(0, x, y);
          }
        }
      } else {
        for (long long run = 0; run < 4; run++) {
          long long x = di[run][0] + i;
          long long y = di[run][1] + j;
          if (cnt[x][y] <= 2 && cnt[x][y] >= 1 && ans[x][y] != '+') {
            ans[x][y] = '+';
            dfs(0, x, y);
          }
        }
      }
    };
    for (long long i = 1; i <= n; i++) {
      for (long long j = 1; j <= m; j++) {
        if (grid[i][j] == 'L') dfs(1, i, j);
      }
    }
    for (long long i = 1; i <= n; i++) {
      for (long long j = 1; j <= m; j++) {
        cout << ans[i][j];
      }
      cout << '\n';
    }
  }
  return 0;
}
