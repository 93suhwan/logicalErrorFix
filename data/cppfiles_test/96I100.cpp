#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mod = 998244353;
ll mod_pow(ll x, ll n, ll mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) {
      res = res * x % mod;
    }
    x = x * x % mod;
    n >>= 1;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll n, x;
  cin >> n >> x;
  vector<vector<vector<ll>>> f(n + 1,
                               vector<vector<ll>>(n + 2, vector<ll>(n + 1, 0)));
  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= i; j++) {
      for (ll h = j; h <= n; h++) {
        if (j == 1) {
          f[i][j][h] = i;
          continue;
        }
        f[i][j][h] = f[i][j][h - 1] * j + f[i][j - 1][h - 1] * (i - j + 1);
        f[i][j][h] %= mod;
      }
    }
  }
  for (ll i = 1; i <= n; i++) {
    f[i][n + 1][0] = 1;
    for (ll h = 1; h <= n; h++) {
      ll a = 0;
      for (ll j = 0; j <= i; j++) {
        a += f[i][j][h];
      }
      f[i][n + 1][h] = a;
    }
  }
  vector<ll> up(n + 1);
  vector<ll> down(n + 1);
  up[0] = 1;
  down[0] = 1;
  for (ll i = 1; i <= n; i++) {
    up[i] = up[i - 1] * i;
    up[i] %= mod;
    down[i] = down[i - 1] * mod_pow(i, mod - 2, mod);
    down[i] %= mod;
  }
  vector<vector<ll>> dp(n, vector<ll>(x, 0));
  dp[n - 1][n - 1] = 1;
  for (ll i = n - 1; i >= 1; i--) {
    for (ll j = i + 1; j < x; j++) {
      for (ll h = i; h < n; h++) {
        dp[i][j] += dp[h][j - i] * up[h + 1] % mod * down[i + 1] % mod *
                    down[h - i] % mod * f[h][n + 1][h - i];
        dp[i][j] %= mod;
      }
    }
  }
  ll ans = 0;
  ans += f[n - 1][n + 1][n];
  for (ll i = n - 1; i >= 1; i--) {
    for (ll j = 0; j < x; j++) {
      if (dp[i][j] == 0) continue;
      for (ll h = i; h >= 1; h--) {
        ll a = min(h, x - j);
        ll c = up[i + 1] % mod * down[i - h] % mod * down[h + 1] % mod;
        ans += dp[i][j] * c % mod * f[i][n + 1][i - h] % mod *
               f[a][n + 1][h + 1] % mod;
        ans %= mod;
      }
    }
  }
  cout << ans << endl;
}
