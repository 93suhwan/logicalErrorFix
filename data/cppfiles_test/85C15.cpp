#include <bits/stdc++.h>
using namespace std;
const int N = 205;
int mod;
int ksm(int b, int n) {
  int res = 1;
  while (n) {
    if (n & 1) res = 1ll * res * b % mod;
    b = 1ll * b * b % mod;
    n >>= 1;
  }
  return res;
}
int f[205][205][205], fac[205], inv[205], a1;
int dp(int i, int j, int k) {
  if (!i) return (k == 0) * (j != 0) * inv[j];
  if (j > a1 + i - 1) return 0;
  if (f[i][j][k] >= 0) return f[i][j][k];
  f[i][j][k] = 0;
  for (int t = 0; t <= j && i * t <= k; ++t)
    f[i][j][k] =
        (f[i][j][k] + 1ll * dp(i - 1, j - t, k - i * t) * inv[t]) % mod;
  return f[i][j][k];
}
void init(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = 1ll * fac[i - 1] * i % mod;
  inv[n] = ksm(fac[n], mod - 2);
  for (int i = n - 1; i >= 0; --i) inv[i] = 1ll * (i + 1) * inv[i + 1] % mod;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n, ans = 0;
  cin >> n >> mod;
  init(n + 1);
  for (a1 = max(n - 20, 1); a1 <= n; ++a1) {
    memset(f, -1, sizeof(f));
    for (int k = 0; k <= a1; ++k) ans = (ans + dp(n + 1 - a1, n, k)) % mod;
  }
  cout << (1ll * ans * fac[n] + 1) % mod;
}
