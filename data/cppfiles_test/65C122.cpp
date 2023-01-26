#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353, N = 2e5 + 5;
int l[N], r[N], mu[N], vis[N];
int cnt, prime[N];
int a[N], b[N];
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
}
int f[55][100005];
int calc(int x, int n, int m) {
  int lim = m / x;
  for (int i = 1; i <= n; ++i)
    a[i] = l[i] / x, b[i] = r[i] / x - l[i] / x, lim -= a[i];
  for (int i = 1; i <= n; ++i)
    if (b[i] <= 0) return 0;
  if (lim <= 0) return 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j <= lim; ++j) f[i][j] = 0;
  for (int j = 1; j <= min(b[1], lim); ++j) f[1][j] = 1;
  for (int j = 1; j <= lim; ++j) f[1][j] += f[1][j - 1];
  for (int i = 2; i <= n; ++i)
    for (int j = 1; j <= lim; ++j) {
      f[i][j] = (f[i - 1][j - 1] + f[i][j - 1]) % mod;
      if (j - b[i] - 1 >= 0)
        f[i][j] = (f[i][j] + mod - f[i - 1][j - b[i] - 1]) % mod;
    }
  return f[n][lim];
}
void solve() {
  int n, m;
  cin >> n >> m;
  init(n + m);
  for (int i = 1; i <= n; ++i) cin >> l[i] >> r[i], l[i]--;
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
