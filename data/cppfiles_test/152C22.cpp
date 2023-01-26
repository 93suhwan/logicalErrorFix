#include <bits/stdc++.h>
using namespace std;
long long int t, n, a[1000007], dp[1000007][2][2];
pair<long long int, long long int> p[1000007][2][2];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> n;
    for (long long int i = 0; i < n; ++i) cin >> a[i];
    for (long long int i = 0; i < n; ++i)
      dp[i][0][0] = dp[i][0][1] = dp[i][1][1] = dp[i][1][0] =
          0x3f3f3f3f3f3f3f3f;
    dp[0][0][0] = dp[0][0][1] = -0x3f3f3f3f3f3f3f3f;
    for (long long int i = 0; i < n - 1; ++i) {
      for (long long int j = 0; j < 2; ++j) {
        for (long long int k = 0; k < 2; ++k) {
          if (dp[i][j][k] == 0x3f3f3f3f3f3f3f3f) continue;
          long long int x = a[i] * (k ? 1 : -1), y = dp[i][j][k];
          if (j) swap(x, y);
          for (long long int nxt = 0; nxt < 2; ++nxt) {
            long long int z = a[i + 1] * (nxt ? 1 : -1);
            if (z > x) {
              if (y < dp[i + 1][0][nxt]) {
                dp[i + 1][0][nxt] = y;
                p[i + 1][0][nxt] = {j, k};
              }
            } else if (z > y) {
              if (x < dp[i + 1][1][nxt]) {
                dp[i + 1][1][nxt] = x;
                p[i + 1][1][nxt] = {j, k};
              }
            }
          }
        }
      }
    }
    bool ok = 1;
    for (long long int i = 0; i < 2; ++i)
      for (long long int j = 0; j < 2; ++j)
        if (dp[n - 1][i][j] != 0x3f3f3f3f3f3f3f3f) ok = 0;
    if (ok) {
      cout << "NO\n";
      continue;
    }
    vector<long long int> ans;
    pair<long long int, long long int> x;
    for (long long int i = 0; i < 2; ++i)
      for (long long int j = 0; j < 2; ++j)
        if (dp[n - 1][i][j] != 0x3f3f3f3f3f3f3f3f) x = {i, j};
    for (long long int i = n - 1; i >= 0; --i) {
      ans.push_back(x.second ? a[i] : -a[i]);
      if (i > 0) x = p[i][x.first][x.second];
    }
    cout << "YES\n";
    reverse(ans.begin(), ans.end());
    for (long long int i : ans) cout << i << ' ';
    cout << '\n';
  }
  return 0;
}
