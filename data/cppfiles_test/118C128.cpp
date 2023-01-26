#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
  return x * f;
}
const long long G1(3);
const int N(1e6 + 10);
const long long G2(332748118);
const long long mod(998244353);
long long ksm(long long a, int b, long long r = 1) {
  for (; b; b >>= 1, a = a * a % mod)
    if (b & 1) r = r * a % mod;
  return r;
}
long long ans;
int n, m;
int d[N];
int rv[N];
long long fac[N];
void NTT(bool sgn, vector<long long> &f) {
  for (int i = (0); i <= (m - 1); i++)
    if (i < rv[i]) f[i] ^= f[rv[i]], f[rv[i]] ^= f[i], f[i] ^= f[rv[i]];
  for (int len = 2; len <= m; len <<= 1) {
    int l = len / 2;
    long long dt = ksm(sgn ? G2 : G1, (mod - 1) / len), w = 1;
    for (int st = 0; st < m; st += len, w = 1)
      for (int i = (st); i <= (st + l - 1); i++) {
        long long fl = f[i], fr = f[i + l] * w % mod;
        f[i] = (fl + fr) % mod, f[i + l] = (fl - fr + mod) % mod,
        (w *= dt) %= mod;
      }
  }
  if (sgn) {
    long long inv = ksm(m, mod - 2);
    for (int i = (0); i <= (m - 1); i++) f[i] = f[i] * inv % mod;
  }
}
vector<long long> solve(int l, int r) {
  if (l == r) return {1ll, 1ll * d[l]};
  int mid = (l + r) >> 1;
  vector<long long> FL = solve(l, mid), FR = solve(mid + 1, r);
  for (m = 1; m <= r - l + 1; m <<= 1)
    ;
  for (int i = (0); i <= (m - 1); i++)
    rv[i] = (rv[i >> 1] >> 1) | ((i & 1) ? (m >> 1) : 0);
  FL.resize(m), FR.resize(m), NTT(0, FL), NTT(0, FR);
  for (int i = (0); i <= (m - 1); i++) FL[i] = FL[i] * FR[i] % mod;
  return NTT(1, FL), FL;
}
signed main() {
  fac[0] = fac[1] = 1;
  n = read();
  long long sgn = 1;
  for (int i = (2); i <= (n); i++) {
    int u = read(), v = read();
    d[i]--, d[u]++, d[v]++, fac[i] = fac[i - 1] * 1ll * i % mod;
  }
  vector<long long> F = solve(1, n);
  for (int i = (0); i <= (n - 1); i++) {
    sgn = (i & 1) ? (-1) : 1;
    ans = (ans + sgn * (fac[n - i] * F[i] % mod) + mod) % mod;
  }
  return cout << ans, 0;
}
