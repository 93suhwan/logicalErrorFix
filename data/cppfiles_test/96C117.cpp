#include <bits/stdc++.h>
using namespace std;
const int maxn = 8e5 + 10;
const int MOD = 998244353;
const int mod = 1e9 + 7;
const long long INF = 8e18;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + ch - '0', ch = getchar();
  return x * f;
}
long long gcd(long long a, long long b) {
  long long res;
  while (b) {
    res = a % b;
    a = b;
    b = res;
  }
  return a;
}
long long qpow(long long a, long long b, const int mo) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mo;
    a = a * a % mo;
    b >>= 1;
  }
  return res;
}
long long qpow(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long slow_mul(long long a, long long b, long long k) {
  long long res = 0;
  while (b) {
    if (b & 1) res = (res + a) % k;
    a = a * 2 % k;
    b >>= 1;
  }
  return res;
}
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
long long ex_gcd(long long a, long long b, long long& x, long long& y) {
  if (!b) {
    x = 1;
    y = 0;
    return a;
  }
  long long res = ex_gcd(b, a % b, y, x);
  y -= a / b * x;
  return res;
}
void init(const int mo = mod) {}
long long c[501][501], f[501][501];
long long pw[501][501];
long long n, x;
void solve() {
  cin >> n >> x;
  c[0][0] = 1;
  for (int i = 1; i <= max(n, x); ++i) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
    }
  }
  pw[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    pw[i][0] = 1;
    for (int j = 1; j <= n; ++j) pw[i][j] = pw[i][j - 1] * i % MOD;
  }
  long long ans = qpow(x, n, MOD);
  for (int i = 1; i <= x; ++i) f[1][i] = i;
  for (int i = 1; i <= x; ++i) f[2][i] = i * (i - 1);
  for (int i = 3; i <= n; ++i) {
    for (int j = 1; j <= x; ++j) {
      for (int k = 0; k < j; ++k) {
        f[i][j] += f[i - k][max(j - (i - 1), 0)] * pw[min(j, i - 1)][k] % MOD *
                   c[i][k] % MOD;
        if (f[i][j] >= MOD) f[i][j] -= MOD;
      }
    }
  }
  ans -= f[n][x];
  cout << (ans % MOD + MOD) % MOD << '\n';
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int _ = 1;
  while (_-- > 0) solve();
  return 0;
}
