#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353, N = 2e5 + 5;
int ksm(int b, int n) {
  int res = 1;
  while (n) {
    if (n & 1) res = 1ll * res * b % mod;
    b = 1ll * b * b % mod;
    n >>= 1;
  }
  return res;
}
int l[N], r[N], f[N], mu[N], vis[N];
int cnt, prime[N];
int fac[N], inv[N];
void init(int n) {
  mu[1] = 1;
  for (int i = 2; i <= n; ++i) {
    if (!vis[i]) vis[i] = 1, mu[i] = mod - 1, prime[++cnt] = i;
    for (int j = 1; j <= cnt; ++j) {
      if (prime[j] > n / i) break;
      vis[i * prime[j]] = 1;
      if (i % prime[j])
        mu[i * prime[j]] = mod - mu[i];
      else
        break;
    }
  }
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = 1ll * fac[i - 1] * i % mod;
  inv[n] = ksm(fac[n], mod - 2);
  for (int i = n - 1; i >= 0; --i) inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
}
int C(int n, int m) {
  if (n < m) return 0;
  return 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod;
}
int calc(int x, int n, int m) {
  for (int i = 0; i <= m / x; ++i) f[i] = 0;
  f[0] = 1;
  int lim = m / x;
  for (int i = 1; i <= n; ++i) {
    int tmp = (l[i] + x - 1) / x;
    lim -= tmp;
  }
  if (lim < 0) return 0;
  for (int i = 1; i <= n; ++i) {
    int tmp = (r[i] - l[i]) / x + 1;
    for (int j = lim; j >= tmp; --j) f[j] = (f[j] + mod - f[j - tmp]) % mod;
  }
  int ans = 0;
  for (int i = 0; i <= lim; ++i)
    ans = (ans + 1ll * f[i] * C(lim - i + n, n)) % mod;
  return ans;
}
void solve() {
  int n, m;
  cin >> n >> m;
  init(n + m);
  for (int i = 1; i <= n; ++i) cin >> l[i] >> r[i];
  int ans = 0;
  for (int i = 1; i <= m; ++i)
    if (mu[i]) ans = (ans + 1ll * mu[i] * calc(i, n, m)) % mod;
  cout << ans << "\n";
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T = 1;
  while (T--) solve();
}
