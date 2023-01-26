#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;
const long long M = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long n, m, s;
  cin >> n >> m >> s;
  vector<vector<pair<long long, long long>>> dp(
      n, vector<pair<long long, long long>>(m));
  dp[n - 1][m - 1] = {0, 0};
  long long result = 0;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
      if (i != n - 1) dp[i][j].first = 1 + dp[i + 1][j].second;
      if (j != m - 1) dp[i][j].second = 1 + dp[i][j + 1].first;
      result += dp[i][j].first + dp[i][j].second + 1;
    }
  }
  long long x, y, prev, curr;
  vector<vector<long long>> b(n, vector<long long>(m, 0));
  for (int i = 0; i < s; i++) {
    cin >> x >> y;
    x--;
    y--;
    long long o_x = x, o_y = y;
    while (x >= 0 || y >= 0) {
      for (int p = x; p >= x - 1; p--) {
        for (int q = y; q >= y - 1; q--) {
          if (p < 0 || q < 0) continue;
          if (p == x - 1 && q == y - 1) continue;
          prev = dp[p][q].first + dp[p][q].second + !(b[p][q]);
          if (p == o_x && q == o_y) b[p][q] = 1 - b[p][q];
          dp[p][q] = {0, 0};
          if (!b[p][q]) {
            if (p != n - 1)
              dp[p][q].first = (!b[p + 1][q]) + dp[p + 1][q].second;
            if (q != m - 1)
              dp[p][q].second = (!b[p][q + 1]) + dp[p][q + 1].first;
          }
          curr = dp[p][q].first + dp[p][q].second + !(b[p][q]);
          result += curr - prev;
        }
      }
      x--;
      y--;
    }
    cout << result << endl;
  }
  return 0;
}
