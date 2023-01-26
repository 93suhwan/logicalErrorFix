#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
inline long long fastpow(long long a, long long n) {
  long long ans = 1;
  while (n) {
    if (n & 1) ans = ans * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return ans;
}
inline long long inv(long long x) { return fastpow(x, mod - 2); }
const long long g = 3, ig = inv(g);
struct Edge {
  long long to, nxt;
} e[500010];
long long ecnt = 0, head[250010];
inline void addedge(long long from, long long to) {
  e[ecnt].to = to;
  e[ecnt].nxt = head[from];
  head[from] = ecnt++;
}
long long r[1100000];
inline void getr(long long n, long long cnt) {
  r[0] = 0;
  for (long long i = 0; i < n; i++)
    r[i] = (r[i >> 1] >> 1) | ((i & 1) << (cnt - 1));
}
inline void NTT(long long *a, long long n, long long op) {
  for (long long i = 0; i < n; i++)
    if (i < r[i]) swap(a[i], a[r[i]]);
  for (long long i = 1; i < n; i <<= 1) {
    long long wn = fastpow(op == 1 ? g : ig, (mod - 1) / (i << 1));
    for (long long j = 0; j < n; j += (i << 1)) {
      long long w = 1;
      for (long long k = 0; k < i; k++, w = w * wn % mod) {
        long long x = a[j + k], y = w * a[i + j + k] % mod;
        a[j + k] = (x + y) % mod;
        a[i + j + k] = (x - y + mod) % mod;
      }
    }
  }
  if (op == -1) {
    long long in = inv(n);
    for (long long i = 0; i < n; i++) a[i] = a[i] * in % mod;
  }
}
long long sz[250010];
void dfs(long long u, long long fa) {
  sz[u] = 0;
  for (long long i = head[u]; i != -1; i = e[i].nxt) {
    long long v = e[i].to;
    if (v == fa) continue;
    dfs(v, u);
    sz[u]++;
  }
}
inline void mul(long long *a, long long *b, long long *c, long long n,
                long long m) {
  long long lim = 1, cnt = 0;
  while (lim <= n + m) lim <<= 1, cnt++;
  getr(lim, cnt);
  NTT(a, lim, 1), NTT(b, lim, 1);
  for (long long i = 0; i < lim; i++) c[i] = a[i] * b[i] % mod;
  NTT(c, lim, -1);
}
long long a[1100010];
inline void Mul(long long l, long long r, long long L, long long R) {
  if (l == r) {
    a[L] = 1, a[L + 1] = sz[l];
    return;
  }
  long long mid = (l + r) >> 1;
  long long Mid = (L + R) >> 1;
  Mul(l, mid, L, Mid);
  Mul(mid + 1, r, Mid, R);
  mul(a + L, a + Mid, a + L, mid - l + 2, r - mid + 1);
  for (long long i = L + (r - l + 2); i < R; i++) a[i] = 0;
}
long long fac[250010];
inline void InitFac(long long n) {
  fac[0] = 1;
  for (long long i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
}
inline long long p1(long long x) { return (x & 1) ? mod - 1 : 1; }
signed main() {
  memset(head, -1, sizeof(head));
  long long n;
  scanf("%lld", &n);
  InitFac(n);
  for (long long i = 1; i < n; i++) {
    long long u, v;
    scanf("%lld %lld", &u, &v);
    addedge(u, v);
    addedge(v, u);
  }
  dfs(1, 1);
  Mul(1, n, 0, 4 * n + 100000);
  long long ans = 0;
  for (long long i = 0; i <= n; i++)
    ans = (ans + a[i] * fac[n - i] % mod * p1(i)) % mod;
  printf("%lld\n", ans);
  return 0;
}
