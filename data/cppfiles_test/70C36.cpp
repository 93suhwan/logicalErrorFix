#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
const long long mod = 1e9 + 7, inv2 = 5e8 + 4;
int n, m;
long long l, r, d, a[11][N], v[11][N];
long long sv[11][N], inv[N], sn[11][N];
long long fac[N], ifac[N];
long long C(long long a, long long b) {
  if (a < b || a < 0 || b < 0)
    return 0;
  else
    return fac[a] * ifac[a - b] % mod * ifac[b] % mod;
}
long long qpow(long long a, long long b) {
  long long ans = 1ll;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++)
    scanf("%lld", &a[1][i]), sv[1][i] = (sv[1][i - 1] + a[1][i]) % mod;
  for (int i = 1; i <= n; i++)
    v[1][i] = i, sn[1][i] = (sn[1][i - 1] + v[1][i]) % mod;
  for (int j = 2; j <= 10; j++) {
    for (int i = 1; i <= n; i++) {
      a[j][i] = a[j - 1][i] * a[1][i] % mod;
      sv[j][i] = (sv[j][i - 1] + a[j][i]) % mod;
    }
  }
  for (int i = 1; i <= n; i++) sn[0][i] = (sn[0][i - 1] + 1) % mod;
  for (int j = 2; j <= 10; j++) {
    for (int i = 1; i <= n; i++) {
      v[j][i] = v[j - 1][i] * v[1][i] % mod;
      sn[j][i] = (sn[j][i - 1] + v[j][i]) % mod;
    }
  }
  fac[0] = 1ll;
  for (int i = 1; i <= 10; i++) fac[i] = fac[i - 1] * i % mod;
  ifac[10] = qpow(fac[10], mod - 2);
  for (int i = 9; i >= 0; i--) ifac[i] = ifac[i + 1] * (i + 1) % mod;
  inv[1] = 1;
  for (int i = 2; i <= n; i++)
    inv[i] = (1LL * (mod - mod / i) * (inv[mod % i]) % mod);
  for (int _ = 1; _ <= m; _++) {
    scanf("%lld %lld %lld", &l, &r, &d);
    long long m = r - l + 1, s = sv[1][r] - sv[1][l - 1];
    s += mod;
    s %= mod;
    long long f =
        (s - (m - 1) * m % mod * inv2 % mod * d % mod + mod) * inv[m] % mod;
    bool flag = 1;
    for (int i = 2; i <= 10; i++) {
      long long lft = 0;
      for (int j = 0; j <= i; j++) {
        lft = (lft + sn[j][m - 1] * C(i, j) % mod * qpow(d, j) % mod *
                         qpow(f, i - j) % mod);
        lft %= mod;
      }
      lft = (lft + qpow(f, i)) % mod;
      flag &= (lft == (sv[i][r] - sv[i][l - 1] + mod) % mod);
    }
    if (flag)
      puts("Yes");
    else
      puts("No");
  }
}
