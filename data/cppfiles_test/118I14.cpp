#include <bits/stdc++.h>
using namespace std;
const long long MAX_N = 8e5 + 7;
const long long MOD = 998244353;
const long long G = 3;
long long rev[MAX_N];
long long f[MAX_N], g[MAX_N];
long long n, m;
vector<vector<long long>> p;
long long f_pow(long long base, long long b, long long mod) {
  long long res = 1;
  while (b) {
    if (b & 1) res = res * base % mod;
    base = base * base % mod;
    b >>= 1;
  }
  return res;
}
void ntt(long long *a, long long n, long long dft) {
  for (long long i = 0; i < n; i++) {
    if (i < rev[i]) swap(a[i], a[rev[i]]);
  }
  for (long long i = 1; i < n; i <<= 1) {
    long long wn = f_pow(G, (MOD - 1) / (i << 1), MOD);
    if (dft < 0) wn = f_pow(wn, MOD - 2, MOD);
    for (long long j = 0; j < n; j += (i << 1)) {
      long long wnk = 1;
      for (long long k = j; k < j + i; k++) {
        long long a1 = a[k], a2 = a[k + i];
        a[k] = (a1 + wnk * a2 % MOD) % MOD;
        a[k + i] = (a1 - wnk * a2 % MOD) % MOD;
        wnk = wnk * wn % MOD;
      }
    }
  }
  if (dft == -1) {
    long long inv = f_pow(n, MOD - 2, MOD);
    for (long long i = 0; i < n; i++) a[i] = a[i] * inv % MOD;
  }
}
vector<long long> div_ntt(long long l, long long r) {
  if (l == r) return p[l];
  long long mid = (l + r) >> 1;
  vector<long long> F, G;
  F = div_ntt(l, mid), G = div_ntt(mid + 1, r);
  n = F.size() - 1, m = G.size() - 1;
  long long N = 1, p = 0;
  while (N < (m + n + 1)) N <<= 1, p++;
  for (long long i = 0; i < N; ++i) rev[i] = f[i] = g[i] = 0;
  for (long long i = 0; i < N; i++)
    rev[i] = ((rev[i >> 1] >> 1) | ((i & 1) << (p - 1)));
  for (long long i = 0; i <= n; i++) f[i] = F[i];
  for (long long i = 0; i <= m; i++) g[i] = G[i];
  ntt(f, N, 1);
  ntt(g, N, 1);
  for (long long i = 0; i < N; i++) {
    f[i] = f[i] * g[i] % MOD;
  }
  ntt(f, N, -1);
  F.resize(m + n + 1);
  for (long long i = 0; i <= (n + m); ++i) F[i] = (f[i] + MOD) % MOD;
  return F;
}
long long _n;
long long deg[MAX_N], fac[MAX_N];
signed main() {
  scanf("%lld", &_n);
  for (long long i = 1; i < _n; ++i) {
    long long x, y;
    scanf("%lld%lld", &x, &y);
    ++deg[x], ++deg[y];
  }
  for (long long i = 2; i <= _n; ++i) --deg[i];
  for (long long i = 1; i <= _n; ++i) {
    vector<long long> t;
    t.push_back(1ll);
    if (deg[i]) t.push_back(deg[i]);
    p.push_back(t);
  }
  vector<long long> F = div_ntt(0, _n - 1);
  for (long long i = 0; i < F.size(); ++i) printf("%lld ", F[i]);
  puts("");
  long long ans = 0, flag = 1;
  fac[0] = 1;
  for (long long i = 1; i <= _n; ++i) fac[i] = fac[i - 1] * i % MOD;
  for (long long i = 0; i < _n && i < F.size(); ++i) {
    ans = (ans + flag * F[i] * fac[_n - i] % MOD) % MOD;
    flag = -flag;
  }
  printf("%lld\n", (ans + MOD) % MOD);
  return 0;
}
