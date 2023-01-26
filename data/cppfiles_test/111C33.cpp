#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2100, MAXM = 60, mod = 998244353;
int power(int a, int n) {
  if (!n) return 1;
  int tmp = power(a, n / 2);
  tmp = 1ll * tmp * tmp % mod;
  if (n & 1) tmp = 1ll * tmp * a % mod;
  return tmp;
}
int n, k, b[MAXN];
int fact[MAXN], inv[MAXN];
long long f[2][MAXN][MAXN];
int l[MAXN], r[MAXN], ans;
long long g[2][MAXN * 2][MAXN];
int main() {
  fact[0] = inv[0] = 1;
  for (int i = (1); i <= (2000); i++) fact[i] = 1ll * i * fact[i - 1] % mod;
  inv[2000] = power(fact[2000], mod - 2);
  for (int i = (1999); i >= (1); i--) inv[i] = 1ll * (i + 1) * inv[i + 1] % mod;
  cin >> n >> k;
  for (int i = (1); i <= (n); i++)
    cin >> b[i], l[i] = max(0, b[i] - k), r[i] = min(i, b[i] + k);
  f[0][0][0] = g[0][0][0] = 1;
  for (int i = (1); i <= (n); i++) {
    if (i > 1)
      for (int j = (0); j <= (i - 2); j++)
        for (int k = (l[i - 2]); k <= (r[i - 2]); k++)
          f[i & 1][j][k] = g[i & 1][j + k][k] = 0;
    for (int x = (i); x >= (0); x--)
      for (int y = (l[i]); y <= (r[i]); y++) {
        if (y + x > i) break;
        long long& ret = f[i & 1][x][y];
        ret = (ret + f[(i - 1) & 1][x][y] * (x + y)) % mod;
        if (x) ret = (ret + f[(i - 1) & 1][x - 1][y]) % mod;
        int R = min(min(r[i - 1], y - 1), x + y - 1);
        if (R >= l[i - 1]) {
          ret = (ret + g[(i - 1) & 1][x + y - 1][R] * inv[x]) % mod;
        }
        g[i & 1][x + y][y] = (g[i & 1][x + y][y - 1] + ret * fact[x]) % mod;
      }
  }
  for (int j = (0); j <= (n); j++)
    for (int k = (l[n]); k <= (r[n]); k++) {
      if (k + j > n) continue;
      ans = (ans + 1ll * f[n & 1][j][k] * fact[n - k] % mod * inv[n - k - j]) %
            mod;
    }
  cout << ans;
  return 0;
}
