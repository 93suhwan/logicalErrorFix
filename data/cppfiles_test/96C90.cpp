#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using ld = long double;
const int N = 2e5 + 3;
const int mod = 998244353;
ll dp[505][505];
int n, x;
ll binexp(ll b, ll e) {
  ll ans = 1ll, y = b;
  while (e) {
    if (e & 1) ans = (ans * y) % mod;
    y = (y * y) % mod;
    e /= 2;
  }
  return ans;
}
ll ifact[505], fact[505];
void init(int m) {
  fact[0] = 1;
  for (int i = 1; i <= m; i++) fact[i] = (fact[i - 1] * 1ll * i) % mod;
  ifact[m] = binexp(fact[m], mod - 2);
  for (int i = m - 1; i >= 0; i--)
    ifact[i] = (ifact[i + 1] * 1ll * (i + 1)) % mod;
}
ll nck(ll a, ll b) {
  if (b > a || b < 0) return 0;
  return (((fact[a] * ifact[a - b]) % mod) * ifact[b]) % mod;
}
int main() {
  scanf("%d %d", &n, &x);
  init(n);
  ll ans = binexp(1ll * x, 1ll * n);
  for (int w = 1; w <= x; w++) {
    dp[1][w] = 1ll;
  }
  for (int k = 2; k <= n; k++) {
    for (int w = k; w <= x; w++) {
      for (int d = max(0, k + k - 1 - w); d < k; d++) {
        ll term = (binexp(k - 1, d) * nck(k - 1, d)) % mod;
        term = (term * dp[k - d][w - (k - 1)]) % mod;
        (dp[k][w] += term) %= mod;
      }
    }
  }
  ll has_winner = 0;
  for (int w = 1; w <= x; w++) {
    has_winner += dp[n][w];
    if (has_winner >= mod) has_winner -= mod;
  }
  has_winner = (has_winner * n) % mod;
  ans -= has_winner;
  if (ans < 0) ans += mod;
  printf("%lld", ans);
  return 0;
}
