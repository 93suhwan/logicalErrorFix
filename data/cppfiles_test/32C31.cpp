#include <bits/stdc++.h>
using namespace std;
int v[100005];
long long sp[100005];
int dp[100005][500];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, m, q, t, i, j, k;
  cin >> t;
  while (t--) {
    cin >> n;
    for (i = 1; i <= n; ++i) {
      cin >> v[i];
      sp[i] = sp[i - 1] + v[i];
    }
    int kmax;
    for (kmax = 1; kmax * (kmax + 1) / 2 <= n; ++kmax)
      ;
    dp[n + 1][1] = 0;
    for (i = 1; i <= n; ++i)
      for (j = 1; j <= kmax; ++j) dp[i][j] = 0;
    for (i = n; i >= 1; --i) dp[i][1] = max(dp[i + 1][1], v[i]);
    for (j = 1; j < kmax; ++j) {
      for (i = n; i >= 1; --i) {
        if (i < n) dp[i][j] = max(dp[i][j], dp[i + 1][j]);
        if (dp[i][j] == 0) continue;
        if (i - 1 >= j + 1 && dp[i][j] > sp[i - 1] - sp[i - 1 - (j + 1)])
          dp[i - 1 - j][j + 1] =
              max(1ll * dp[i - 1 - j][j + 1], sp[i - 1] - sp[i - 1 - (j + 1)]);
      }
    }
    for (j = 1; j <= kmax; ++j)
      if (dp[1][j] == 0) break;
    cout << j - 1 << '\n';
  }
}
