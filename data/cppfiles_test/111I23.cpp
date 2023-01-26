#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 2010;
const long long MAXK = 55;
const long long INF = 2e9;
const double eps = 1e-6;
const double PI = acos(-1);
const long long mod = 998244353;
long long n, k, Ans;
long long b[MAXN], L[MAXN], R[MAXN];
long long fac[MAXN], ifac[MAXN], Inv[MAXN];
long long dp[2][MAXN][MAXK << 1];
long long coef[2][MAXN][MAXK << 1];
template <typename T>
inline bool read(T &a) {
  a = 0;
  char c = getchar();
  long long f = 1;
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    a = a * 10 + (c ^ 48);
    c = getchar();
  }
  return a *= f, true;
}
template <typename A, typename... B>
inline bool read(A &x, B &...y) {
  return read(x) && read(y...);
}
void pushup(long long i) {
  for (long long j = max(0ll, L[i]); j <= min(i, R[i]); ++j)
    for (long long c = 0; c <= i; ++c) {
      if (j > L[i] && coef[(i)&1][(j - 1) - b[i] + k][c + 1])
        (coef[(i)&1][(j)-b[i] + k][c] +=
         coef[(i)&1][(j - 1) - b[i] + k][c + 1] * (c + 1)) %= mod;
      (dp[(i)&1][(j)-b[i] + k][c] += coef[(i)&1][(j)-b[i] + k][c]) %= mod;
    }
}
signed main() {
  read(n), read(k);
  Inv[1] = fac[0] = ifac[0] = 1;
  for (long long i = 1; i <= n; ++i) read(b[i]);
  for (long long i = 0; i <= n; ++i) L[i] = b[i] - k, R[i] = b[i] + k;
  for (long long i = 2; i < MAXN; ++i)
    Inv[i] = Inv[mod % i] * (mod - mod / i) % mod;
  for (long long i = 1; i < MAXN; ++i) {
    fac[i] = fac[i - 1] * i % mod;
    ifac[i] = ifac[i - 1] * Inv[i] % mod;
  }
  dp[(0) & 1][(0) - b[0] + k][0] = 1;
  for (long long i = 0; i < n; ++i) {
    memset(dp[(i + 1) & 1], 0, sizeof dp[(i + 1) & 1]);
    memset(coef[(i + 1) & 1], 0, sizeof coef[(i + 1) & 1]);
    for (long long j = max(0ll, L[i]); j <= min(i, R[i]); ++j) {
      for (long long c = 0, p; c <= i; ++c) {
        if (!dp[(i)&1][(j)-b[i] + k][c]) continue;
        if (L[i + 1] <= j && j <= R[i + 1]) {
          (dp[(i + 1) & 1][(j)-b[i + 1] + k][c] +=
           dp[(i)&1][(j)-b[i] + k][c] * (j + c)) %= mod;
          (dp[(i + 1) & 1][(j)-b[i + 1] + k][c + 1] +=
           dp[(i)&1][(j)-b[i] + k][c]) %= mod;
        }
        if (j <= R[i + 1]) {
          p = max(j + 1, L[i + 1]) - j;
          if (p - 1 <= c)
            (coef[(i + 1) & 1][(j + p) - b[i + 1] + k][c - p + 1] +=
             dp[(i)&1][(j)-b[i] + k][c] * fac[c] % mod * ifac[c - p + 1]) %=
                mod;
        }
      }
    }
    pushup(i + 1);
  }
  for (long long j = max(0ll, L[n]); j <= min(n, R[n]); ++j)
    for (long long c = 0; c <= n; ++c)
      if (c <= n - j && dp[(n)&1][(j)-b[n] + k][c])
        (Ans += dp[(n)&1][(j)-b[n] + k][c] * fac[n - j] % mod *
                ifac[n - j - c]) %= mod;
  printf("%lld\n", Ans);
  return 0;
}
