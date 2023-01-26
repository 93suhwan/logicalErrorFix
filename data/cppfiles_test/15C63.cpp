#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * w;
}
const long long p = 1e9 + 7;
long long qp(long long x, long long y) {
  long long res = 1;
  for (long long t = x; y; y >>= 1, t = t * t % p)
    if (y & 1) res = res * t % p;
  return res;
}
vector<long long> e[1003];
long long fac[1003], ifac[1003];
long long C(long long n, long long m) {
  return fac[n] * ifac[n - m] % p * ifac[m] % p;
}
long long n, K;
long long cnt[1003][1003];
void dfs(long long x, long long fa, long long dep, long long id) {
  ++cnt[id][dep];
  for (long long i : e[x])
    if (i != fa) dfs(i, x, dep + 1, id);
  return;
}
long long f[1003];
signed main() {
  fac[0] = ifac[0] = 1;
  for (long long i = 1; i <= 1000; ++i)
    fac[i] = fac[i - 1] * i % p, ifac[i] = qp(fac[i], p - 2);
  for (long long T = read(); T--;) {
    n = read(), K = read();
    for (long long i = 1; i <= n; ++i) e[i].clear();
    for (long long i = 1; i < n; ++i) {
      long long u = read(), v = read();
      e[u].push_back(v);
      e[v].push_back(u);
    }
    if (K == 2) {
      printf("%lld\n", n * (n - 1) / 2);
      continue;
    }
    long long ans = 0;
    for (long long i = 1; i <= n; ++i) {
      long long c = 0;
      for (long long j = 1; j <= n; ++j)
        for (long long k = 1; k <= n; ++k) cnt[j][k] = 0;
      for (long long j : e[i]) dfs(j, i, 1, ++c);
      for (long long j = 1; j <= n; ++j) {
        for (long long k = 1; k <= n; ++k) f[k] = 0;
        f[0] = 1;
        for (long long k = 1; k <= c; ++k) {
          for (long long l = n; l >= 1; --l)
            f[l] = (f[l] + f[l - 1] * cnt[k][j]) % p;
        }
        ans = (ans + f[K]) % p;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
