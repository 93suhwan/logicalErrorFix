#include <bits/stdc++.h>
using namespace std;
const long long inf = 2e9;
int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  long long n, m;
  string s, t;
  cin >> n >> m >> s >> t;
  vector<long long> pi(m, 0), nxt(m, 0);
  for (long long i = 1; i < m; i++) {
    {
      t[i] = char('0' + (t[i] - '0') ^ 1);
      long long j = pi[i - 1];
      while (j > 0 and t[i] != t[j]) {
        j = pi[j - 1];
      }
      if (t[i] == t[j]) j++;
      nxt[i] = j;
      t[i] = char('0' + (t[i] - '0') ^ 1);
    }
    {
      long long j = pi[i - 1];
      while (j > 0 and t[i] != t[j]) {
        j = pi[j - 1];
      }
      if (t[i] == t[j]) j++;
      pi[i] = j;
    }
  }
  s = '#' + s;
  long long dp[2][m][n - m + 2];
  fill(**dp, **dp + sizeof dp / sizeof(long long), inf);
  dp[0][0][0] = 0;
  for (long long i = 0; i < n; i++) {
    for (long long j = 0; j < m; j++) {
      for (long long k = 0; k < n - m + 2; k++) {
        dp[(i & 1) ^ 1][j][k] = inf;
      }
    }
    for (long long j = 0; j < m; j++) {
      for (long long k = 0; k < n - m + 2; k++) {
        if (dp[i & 1][j][k] == inf) continue;
        if (j == m - 1) {
          dp[(i & 1) ^ 1][pi.back()][k + 1] =
              min(dp[(i & 1) ^ 1][pi.back()][k + 1],
                  dp[i & 1][j][k] + (s[i + 1] != t[j]));
        } else {
          dp[(i & 1) ^ 1][j + 1][k] = min(dp[(i & 1) ^ 1][j + 1][k],
                                          dp[i & 1][j][k] + (s[i + 1] != t[j]));
        }
        dp[(i & 1) ^ 1][nxt[j]][k] = min(dp[(i & 1) ^ 1][nxt[j]][k],
                                         dp[i & 1][j][k] + (s[i + 1] == t[j]));
      }
    }
  }
  for (long long i = 0; i < n - m + 2; i++) {
    long long mn = inf;
    for (long long j = 0; j < m; j++) {
      mn = min(mn, dp[n & 1][j][i]);
    }
    if (mn == inf) mn = -1;
    cout << mn << ' ';
  }
}
