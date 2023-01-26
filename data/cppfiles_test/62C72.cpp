#include <bits/stdc++.h>
using namespace std;
void test_case() {
  int n, m, q;
  cin >> n >> m >> q;
  int64_t total = 0;
  vector<vector<pair<int64_t, int64_t>>> dp(
      n + 1, vector<pair<int64_t, int64_t>>(m + 1));
  auto cnt = [&dp](int i, int j) {
    return dp[i][j].first + dp[i][j].second - 1;
  };
  auto update = [&dp, &cnt](int i, int j) {
    dp[i][j].second = dp[i - 1][j].first + 1;
    dp[i][j].first = dp[i][j - 1].second + 1;
    return cnt(i, j);
  };
  auto locked = [&dp](int i, int j) {
    return dp[i][j].first == 0 && dp[i][j].second == 0;
  };
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      update(i, j);
      total += cnt(i, j);
    }
  }
  while (q--) {
    int i, j;
    cin >> i >> j;
    if (!locked(i, j)) {
      total -= cnt(i, j);
      dp[i][j] = make_pair(0, 0);
    } else
      total += update(i, j);
    for (++i, ++j; i - 1 <= n && j - 1 <= m; ++i, ++j) {
      if (j <= m && !locked(i - 1, j)) {
        total -= cnt(i - 1, j);
        total += update(i - 1, j);
      }
      if (i <= n && !locked(i, j - 1)) {
        total -= cnt(i, j - 1);
        total += update(i, j - 1);
      }
      if (i <= n && j <= m && !locked(i, j)) {
        total -= cnt(i, j);
        total += update(i, j);
      }
    }
    cout << total << '\n';
  }
}
int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int Case = 1;
  for (int i = 1; i <= Case; i++) {
    test_case();
  }
  return 0;
}
