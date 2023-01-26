#include <bits/stdc++.h>
using namespace std;
namespace fastIO {
bool IOerror = 0;
inline char nc() {
  static char buf[100000], *p1 = buf + 100000, *pend = buf + 100000;
  if (p1 == pend) {
    p1 = buf;
    pend = buf + fread(buf, 1, 100000, stdin);
    if (pend == p1) {
      IOerror = 1;
      return -1;
    }
  }
  return *p1++;
}
inline bool blank(char ch) {
  return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}
inline long long read() {
  long long ans = 0, f = 1;
  char c = nc();
  while (c > '9' || c < '0') {
    if (c == '-') f = -1;
    c = nc();
  }
  while (c >= '0' && c <= '9') {
    ans = ans * 10 + c - '0';
    c = nc();
  }
  return ans * f;
}
};  // namespace fastIO
using namespace fastIO;
inline void write(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x / 10) write(x / 10);
  putchar((char)(x % 10) + '0');
}
template <typename T>
inline T Abs(T a) {
  return a > 0 ? a : -a;
};
template <typename T, typename TT>
inline T Min(T a, TT b) {
  return a < b ? a : b;
}
template <typename T, typename TT>
inline T Max(T a, TT b) {
  return a < b ? b : a;
}
const long long N = 2005, K = 105, mod = 998244353;
long long n, k, l[N], r[N], dp[2][N][N], sm[2][N][N], jc[N], inv[N];
inline long long q_pow(long long a, long long b) {
  long long c = 1;
  while (b) {
    if (b & 1) c = a * c % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return c;
}
inline void init(long long x) {
  jc[0] = 1;
  for (long long i = 1; i <= x; ++i) jc[i] = jc[i - 1] * i % mod;
  inv[x] = q_pow(jc[x], mod - 2);
  for (long long i = x - 1; i >= 0; --i) inv[i] = inv[i + 1] * (i + 1) % mod;
}
signed main() {
  init(2000);
  n = read();
  k = read();
  for (long long i = 1; i <= n; ++i) {
    long long x = read();
    l[i] = Max(0, x - k);
    r[i] = Min(i, x + k);
  }
  dp[0][0][0] = 1;
  sm[0][0][0] = 1;
  for (long long I = 1, i = 1; I <= n; ++I, i ^= 1) {
    for (long long j = 0; j <= I; ++j)
      for (long long k = l[I]; k <= r[I] && k <= j; ++k) {
        dp[i][j][k] = (dp[i][j][k] + dp[i ^ 1][j][k] * j % mod) % mod;
        if (j) dp[i][j][k] = (dp[i][j][k] + dp[i ^ 1][j - 1][k]) % mod;
        if (j && k)
          dp[i][j][k] = (dp[i][j][k] + sm[i ^ 1][j - 1][Min(k - 1, r[I - 1])] *
                                           inv[j - k] % mod) %
                        mod;
        sm[i][j][k] = dp[i][j][k] * jc[j - k] % mod;
        if (k) sm[i][j][k] = (sm[i][j][k] + sm[i][j][k - 1]) % mod;
      }
    for (long long j = 0; j <= I - 1; ++j)
      for (long long k = l[I - 1]; k <= r[I - 1] && k <= j; ++k)
        dp[i ^ 1][j][k] = sm[i ^ 1][j][k] = 0;
  }
  long long ans = 0;
  for (long long i = 0; i <= n; ++i)
    for (long long j = l[n]; j <= r[n] && j <= i; ++j)
      ans = (ans + dp[n & 1][i][j] * jc[n - j] % mod * inv[n - i] % mod) % mod;
  write(ans);
  return 0;
}
