#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
using ll = long long;
int main() {
  ll t;
  cin >> t;
  while (t--) {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) {
      cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<ll>());
    ll dp[k + 1][k + 1];
    for (ll i = 0; i < k + 1; ++i) {
      for (ll j = 0; j < k + 1; ++j) {
        dp[i][j] = LLONG_MAX;
      }
    }
    dp[0][0] = accumulate(a.begin(), a.end(), 0LL);
    for (ll i = 0; i < k; ++i) {
      for (ll j = 0; j <= i; ++j) {
        ll l = 2 * i - j;
        ll r = n - j;
        dp[i + 1][j] =
            min(dp[i + 1][j], dp[i][j] - (a[l] + a[l + 1] - (a[l + 1] / a[l])));
        dp[i + 1][j + 1] = min(
            dp[i + 1][j + 1], dp[i][j] - (a[l] + a[r - 1] - (a[r - 1] / a[l])));
      }
    }
    ll res = LLONG_MAX;
    for (ll i = 0; i <= k; ++i) {
      res = min(res, dp[k][i]);
    }
    cout << res << endl;
  }
  return 0;
}
