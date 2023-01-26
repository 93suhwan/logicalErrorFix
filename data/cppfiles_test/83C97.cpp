#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll maxn = 5e3 + 10;
ll dp[maxn];
ll lcp[maxn][maxn];
ll n;
char s[maxn];
signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  ll t;
  cin >> t;
  while (t--) {
    memset(dp, 0, sizeof dp);
    cin >> n >> (s + 1);
    for (ll i = n; i >= 1; --i) {
      for (ll j = n; j >= 1; --j) {
        lcp[i][j] = (s[i] == s[j] ? 1 + lcp[i + 1][j + 1] : 0);
      }
    }
    dp[1] = n;
    ll res = n;
    for (ll i = 2; i <= n; ++i) {
      dp[i] = n - i + 1;
      for (ll j = 1; j < i; ++j) {
        if (i + lcp[i][j] > n || s[j + lcp[j][i]] > s[i + lcp[j][i]])
          continue;
        else
          dp[i] = max(dp[i], dp[j] + (n - i + 1 - lcp[j][i]));
      }
      res = max(res, dp[i]);
    }
    cout << res << '\n';
  }
}
