#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using ll = long long;
using ld = long double;
const ll mod = 998244353;
ll gcd(ll a, ll b) {
  a = abs(a);
  b = abs(b);
  if (a == 0 or b == 0) return a + b;
  return gcd(b, a % b);
}
ll sum(ll a, ll b) {
  a += b;
  a %= mod;
  return a;
}
ll sub(ll a, ll b) {
  a += mod - b;
  a %= mod;
  return a;
}
inline ll mul(ll a, ll b) {
  if (a * b < mod) return a * b;
  return a * b % mod;
}
inline ll pew(ll a, ll b) {
  ll res = 1;
  while (b) {
    if (b & 1) res = mul(res, a);
    a = mul(a, a);
    b /= 2;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  ll n, k;
  cin >> n >> k;
  vector<ll> b(n + 1);
  for (ll i = 0; i < n; i++) {
    cin >> b[i + 1];
  }
  b[0] = 0;
  vector<vector<ll>> dp(2 * k + 1, vector<ll>(n + 1));
  vector<vector<ll>> dp2(2 * k + 1, vector<ll>(n + 1));
  dp[k][0] = 1;
  for (ll i = 1; i <= n; i++) {
    for (ll j = 0; j <= 2 * k; j++) {
      for (ll d = 0; d <= n; d++) dp2[j][d] = 0;
    }
    for (ll j = max(0LL, k - b[i - 1]); j <= 2 * k; j++) {
      ll j2 = j + b[i - 1] - b[i] + 1;
      ll x = j + b[i - 1] - k;
      if (x < 0 or x > n) continue;
      if (j2 > 2 * k) continue;
      for (ll d = max(0LL, -j2); d < i; d++) {
        if (j2 < 0)
          dp2[0][d + j2] = (dp2[0][d + j2] + dp[j][d]) % mod;
        else
          dp2[j2][d] = (dp2[j2][d] + dp[j][d]) % mod;
      }
    }
    for (ll j = 0; j < 2 * k; j++) {
      for (ll d = 1; d <= i; d++) {
        dp2[j + 1][d - 1] = (dp2[j + 1][d - 1] + dp2[j][d]) % mod;
      }
    }
    for (ll j = max(0LL, k - b[i - 1]); j <= 2 * k; j++) {
      ll j2 = j + b[i - 1] - b[i];
      ll x = j + b[i - 1] - k;
      if (x < 0 or x > n) continue;
      if (j2 >= 0 and j2 <= 2 * k) {
        for (ll d = 0; d < i; d++) {
          dp2[j2][d] = (dp2[j2][d] + dp[j][d] * (d + x)) % mod;
          dp2[j2][d + 1] = (dp2[j2][d + 1] + dp[j][d] * (d + 1)) % mod;
        }
      }
    }
    swap(dp, dp2);
  }
  vector<vector<ll>> c(n + 2);
  for (ll i = 0; i <= n + 1; i++) {
    c[i].resize(i + 1);
    c[i][0] = c[i][i] = 1;
    for (ll j = 1; j < i; j++) c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
  }
  ll A = 0;
  for (ll j = 0; j <= 2 * k; j++) {
    ll x = b[n] + j - k;
    if (x < 0 or x > n) continue;
    ll Q = 1;
    for (ll d = 0; d <= n - x; d++) {
      A = (A + dp[j][d] * c[n - x][d]) % mod;
    }
  }
  cout << A << endl;
}
