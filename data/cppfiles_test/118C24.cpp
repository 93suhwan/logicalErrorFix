#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + (c - '0');
    c = getchar();
  }
  return x * f;
}
long long n, deg[2001000], a[2001000], b[2001000], r[2001000], L, maxx,
    fac[2001000], g = 3, g2 = 332748118;
long long qpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % 998244353;
    b >>= 1, a = a * a % 998244353;
  }
  return ans;
}
void ntt(long long *a, long long tag) {
  for (long long i = 0; i <= maxx - 1; i++)
    if (i < r[i]) swap(a[i], a[r[i]]);
  for (long long i = 1; i < maxx; i <<= 1) {
    long long w = qpow(tag == 1 ? g : g2, (998244353 - 1) / (i << 1));
    for (long long j = 0; j < maxx; j += (i << 1)) {
      long long w2 = 1, x, y;
      for (long long k = 0; k <= i - 1; k++) {
        x = a[j + k], y = w2 * a[j + k + i] % 998244353;
        a[j + k] = (x + y) % 998244353, a[j + k + i] = (x - y) % 998244353,
              w2 = (w2 * w) % 998244353;
      }
    }
  }
}
vector<long long> NTT(vector<long long> A, vector<long long> B) {
  long long n = A.size() - 1, m = B.size() - 1;
  for (long long i = 0; i <= n; i++) a[i] = A[i] % 998244353;
  for (long long i = 0; i <= m; i++) b[i] = B[i] % 998244353;
  L = 0, maxx = 1;
  for (maxx = 1; maxx <= n + m; maxx <<= 1) L++;
  for (long long i = 0; i <= maxx - 1; i++) r[i] = 0;
  for (long long i = 0; i <= maxx - 1; i++)
    r[i] = (r[i >> 1] >> 1) | ((i & 1) << (L - 1));
  ntt(a, 1), ntt(b, 1);
  for (long long i = 0; i <= maxx - 1; i++) a[i] = (a[i] * b[i]) % 998244353;
  ntt(a, -1);
  long long inv = qpow(maxx, 998244353 - 2);
  for (long long i = 0; i <= n + m; i++) a[i] = a[i] * inv % 998244353;
  vector<long long> AA;
  AA.clear();
  for (long long i = 0; i <= n + m; i++) AA.push_back(a[i]);
  for (long long i = 0; i <= 3 * (n + m); i++) a[i] = b[i] = 0;
  return AA;
}
vector<long long> solve(long long l, long long r) {
  if (l == r) {
    vector<long long> c(2);
    c[0] = 1;
    c[1] = deg[l];
    return c;
  }
  long long mid = (l + r) >> 1;
  return NTT(solve(l, mid), solve(mid + 1, r));
}
signed main() {
  n = read();
  for (long long i = 1; i <= n - 1; i++) deg[read()]++, deg[read()]++;
  for (long long i = 2; i <= n; i++) deg[i]--;
  vector<long long> ac = solve(1, n);
  long long ans = 0;
  fac[0] = 1;
  for (long long i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % 998244353;
  for (long long i = 0; i <= n; i++)
    ans += (i % 2 == 0 ? 1 : -1) * fac[n - i] * ac[i] % 998244353,
        ans %= 998244353;
  printf("%lld\n", (ans + 998244353) % 998244353);
  return 0;
}
