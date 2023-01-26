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
    ll dp[n + 5][2];
    for (ll i = 0; i < (n + 5); ++i) dp[i][1] = dp[i][0] = 0;
    dp[0][0] = 1;
    for (ll i = 0; i < (n); ++i) {
      ll x = arr[i];
      if (x > 0)
        dp[x - 1][1] = (dp[x - 1][1] + dp[x - 1][0] + dp[x - 1][1]) % mod;
      dp[x + 1][0] = (dp[x + 1][0] + dp[x][0] + dp[x + 1][0]) % mod;
      dp[x + 1][1] = (dp[x + 1][1] * 2) % mod;
    }
    ll ans = 0;
    for (ll i = 0; i <= (n + 4); ++i) {
      ans = (ans + dp[i][1] + dp[i][0]) % mod;
    }
    ans--;
    cout << ans << '\n';
  }
  return 0;
}
