#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
constexpr int INF = 0x3f3f3f3f;
void SolveTask() {
  int n, m;
  string a, b;
  cin >> n >> m >> a >> b;
  vector<vector<int>> pf(m + 1, vector<int>(2, 0));
  for (int i = 0; i <= m; ++i) {
    for (int r = min(i, m - 1); r >= 0; --r) {
      bool ok = true;
      for (int j = r - 1, h = i - 1; j >= 0; --j, --h) {
        if (b[j] != b[h]) {
          ok = false;
          break;
        }
      }
      if (ok) {
        pf[i][b[r] - '0'] = max(pf[i][b[r] - '0'], r + 1);
      }
    }
  }
  const auto SetMin = [](int& x, int y) { x = min(x, y); };
  vector<vector<vector<int>>> dp(
      n + 1, vector<vector<int>>(n + 2, vector<int>(m + 1, INF)));
  dp[0][0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= max(0, i - m + 2); ++j) {
      for (int k = 0; k <= min(i, m); ++k) {
        if (dp[i][j][k] == INF) {
          continue;
        }
        const int c = a[i] - '0';
        SetMin(dp[i + 1][j + (pf[k][c] == m)][pf[k][c]], dp[i][j][k]);
        SetMin(dp[i + 1][j + (pf[k][c ^ 1] == m)][pf[k][c ^ 1]],
               dp[i][j][k] + 1);
      }
    }
  }
  vector<int> ans(n - m + 2, INF);
  for (int p = 0; p <= m; ++p) {
    for (int j = 0; j <= n - m + 2; ++j) {
      if (dp[n][j][p] != INF) {
        SetMin(ans[j], dp[n][j][p]);
      }
    }
  }
  for (int x : ans) {
    x = x == INF ? -1 : x;
    cout << x << ' ';
  }
  cout << "\n";
}
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int test_cases = 1;
  for (int yt = 1; yt <= test_cases; ++yt) {
    SolveTask();
  }
  return 0;
}
