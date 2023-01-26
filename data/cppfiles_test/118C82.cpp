#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target( \
    "sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read() {
  int s = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
  return s * w;
}
const int p = 998244353;
int qp(int x, int y) {
  int res = 1;
  for (int t = x; y; y >>= 1, t = 1ll * t * t % p)
    if (y & 1) res = 1ll * res * t % p;
  return res;
}
inline unsigned long long calc(const unsigned long long &x) {
  return x - (__uint128_t(x) * 9920937979283557439ull >> 93) * 998244353;
}
int A[524288], B[524288], C[524288];
int rev[524288], N = 2;
inline void init() {
  int d = N >> 2;
  rev[0] = 0, rev[1] = N >> 1;
  for (int i = 2; i < N; i <<= 1, d >>= 1)
    for (int j = 0; j < i; ++j) rev[i + j] = rev[j] + d;
  return;
}
inline void NTT(int *F) {
  for (int i = 0; i < (N >> 1); ++i) F[i] = F[0];
  for (int i = (N >> 1); i < N; ++i) F[i] = F[N >> 1];
  int w0 = 1, w = qp(3, 998244352 / N);
  for (int i = 0; i < (N >> 1); ++i) {
    int x = F[i], y = calc(1ull * w0 * F[i + (N >> 1)]);
    ((F[i] = x + y) >= p) && (F[i] -= p),
        ((F[i + (N >> 1)] = x - y) < 0) && (F[i + (N >> 1)] += p),
        w0 = calc(1ull * w0 * w);
  }
}
inline void NTT_(int *F) {
  for (int i = 0; i < N; ++i)
    if (rev[i] > i) F[i] ^= F[rev[i]] ^= F[i] ^= F[rev[i]];
  for (int len = 2, M = 1; len <= N; len <<= 1, M <<= 1) {
    int w = qp(332748118, 998244352 / len);
    for (int l = 0; l < N; l += len) {
      int w0 = 1;
      for (int i = l; i < l + M; ++i) {
        int x = F[i], y = calc(1ull * w0 * F[i + M]);
        ((F[i] = x + y) >= p) && (F[i] -= p),
            ((F[i + M] = x - y) < 0) && (F[i + M] += p),
            w0 = calc(1ull * w0 * w);
      }
    }
  }
}
int fac[300003], ifac[300003];
bool f[300003];
int a[300003], cnt[300003];
vector<int> e[300003];
void dfs(int x, int fa = 0) {
  for (int y : e[x])
    if (y != fa) ++a[x], dfs(y, x);
  return;
}
signed main() {
  int n = read();
  fac[0] = ifac[0] = 1;
  for (int i = 1; i < n; ++i) {
    int x = read(), y = read();
    e[x].push_back(y);
    e[y].push_back(x);
  }
  dfs(1);
  for (int i = 1; i <= n; ++i) ++cnt[a[i]];
  for (int i = 1; i <= n; ++i)
    fac[i] = 1ll * fac[i - 1] * i % p, ifac[i] = qp(fac[i], p - 2);
  for (; N <= (n << 1); N <<= 1)
    ;
  init(), A[0] = 1, NTT(A);
  for (int i = 1; i <= n; ++i)
    if (cnt[i]) {
      memset(B, 0, sizeof(B));
      B[N >> 1] = i, B[0] = 1, NTT(B);
      for (int j = 0; j < N; ++j) A[j] = 1ll * A[j] * qp(B[j], cnt[i]) % p;
    }
  NTT_(A);
  int ans = 0, inv = qp(N, p - 2);
  for (int i = 0; i <= n; ++i) A[i] = 1ll * A[i] * inv % p;
  for (int i = 0; i <= n; ++i)
    ans = (ans + 1ll * fac[n - i] * ((i & 1) ? p - A[i] : A[i])) % p;
  printf("%d\n", ans);
  return 0;
}
