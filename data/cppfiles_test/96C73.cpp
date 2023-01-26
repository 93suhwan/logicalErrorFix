#include <bits/stdc++.h>
using namespace std;
const long long N = 505, mod = 998244353;
long long f[N][N], n, x, fac[N], inv[N];
void upd(long long &x, long long y) { x = (x + y) % mod; }
long long qp(long long A, long long B) {
  long long C = 1;
  for (; B; B >>= 1, A = 1ll * A * A % mod)
    if (B & 1) C = 1ll * A * C % mod;
  return C;
}
long long C(long long A, long long B) {
  return 1ll * fac[B] * inv[A] % mod * inv[B - A] % mod;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> x;
  fac[0] = inv[0] = 1;
  for (register long long i = (1); i <= (n); ++i)
    fac[i] = 1ll * i * fac[i - 1] % mod;
  inv[n] = qp(fac[n], mod - 2);
  for (register long long i = (n - 1); i >= (1); --i)
    inv[i] = 1ll * (i + 1) * inv[i + 1] % mod;
  for (register long long i = (2); i <= (n); ++i)
    for (register long long j = (1); j <= (x); ++j) {
      if (j < i) {
        f[i][j] = qp(j, i);
        continue;
      }
      f[i][j] = qp(i - 1, i);
      for (register long long k = (2); k <= (i); ++k)
        upd(f[i][j],
            1ll * C(k, i) * qp(i - 1, i - k) % mod * f[k][j - i + 1] % mod);
    }
  cout << f[n][x] << '\n';
  return 0;
}
