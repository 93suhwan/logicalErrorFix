#include <bits/stdc++.h>
using namespace std;
const int maxn = 505, mod = 998244353;
long long c[maxn][maxn], f[maxn][maxn];
long long qpow(long long a, int b) {
  long long res(1);
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
int main() {
  cin.sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
  int n, x;
  c[0][0] = 1;
  for (int i = 1; i <= 500; ++i) {
    c[i][0] = 1;
    for (int j = 1; j <= i; ++j) {
      c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
      if (c[i][j] >= mod) c[i][j] -= mod;
    }
  }
  cin >> n >> x;
  f[n][0] = 1;
  for (int i = n; i >= 2; --i) {
    for (int j = 0; j < x; ++j) {
      if (!f[i][j]) continue;
      int r = min(i + j - 1, x);
      for (int k = 0; k <= i; ++k) {
        f[k][r] =
            (f[k][r] + f[i][j] * c[i][k] % mod * qpow(r - j, i - k)) % mod;
      }
    }
  }
  long long ans(0);
  for (int i = 1; i <= x; ++i) {
    ans += f[0][i];
    if (ans >= mod) ans -= mod;
  }
  cout << ans << '\n';
  return 0;
}
