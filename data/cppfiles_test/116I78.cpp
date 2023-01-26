#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using ld = long double;
const ll mod = 998244353;
ll n;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  ll t;
  cin >> t;
  while (t--) {
    cin >> n;
    ll arr[n];
    for (ll i = 0; i < (n); ++i) cin >> arr[i];
    ;
    vector<pair<ll, ll> > dp(n + 5);
    for (ll i = 0; i < (n); ++i) {
      if (arr[i] == 0) {
        ll ng = 0, g = 0;
        ng = (dp[0].first + 1) % mod;
        dp[0].first = (dp[0].first + ng) % mod;
      } else if (arr[i] == 1) {
        ll ng = 0, g = 0;
        ng = dp[1].first;
        ng = (ng + dp[0].first) % mod;
        g = (dp[1].second + 1) % mod;
        dp[1].first = (dp[1].first + ng) % mod;
        dp[1].second = (dp[1].second + g) % mod;
      } else {
        ll ng = 0, g = 0;
        pair<ll, ll> c = dp[arr[i]];
        ng = (ng + c.first) % mod, g = (g + c.second) % mod;
        c = dp[arr[i] - 1];
        ng = (ng + c.first) % mod;
        c = dp[arr[i] - 2];
        g = (g + c.first) % mod;
        dp[arr[i]].first = (dp[arr[i]].first + ng) % mod;
        dp[arr[i]].second = (dp[arr[i]].second + g) % mod;
      }
    }
    ll ans = 0;
    for (ll i = 0; i < (n + 1); ++i) {
      ans = ((ans + dp[i].first) % mod + dp[i].second) % mod;
    }
    cout << ans << '\n';
  }
  return 0;
}
