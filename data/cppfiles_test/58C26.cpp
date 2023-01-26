#include <bits/stdc++.h>
using namespace std;
const long long N = 4 * 1e5 + 100;
long long t, n, m, x[N], y[N], fac[N], inv[N], pos[N];
inline void add(long long &a, long long b) {
  a = ((a + b >= 998244353) ? a + b - 998244353 : a + b);
}
inline void del(long long &a, long long b) {
  a = ((a - b < 0) ? a - b + 998244353 : a - b);
}
inline void mul(long long &a, long long b) { a = a * b % 998244353; }
inline long long C(long long n, long long m) {
  return fac[n] * inv[m] % 998244353 * inv[n - m] % 998244353;
}
inline long long m_pow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) mul(ans, a);
    b >>= 1;
    mul(a, a);
  }
  return ans;
}
inline long long read() {
  long long f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  return x * f;
}
struct bit {
  long long sh[N], ti[N];
  inline long long lowbit(long long x) { return x & (-x); }
  inline void change(long long x, long long v) {
    while (x <= n) sh[x] += v, x += lowbit(x);
  }
  inline long long query(long long x) {
    long long ans = 0;
    while (x) ans += sh[x], x -= lowbit(x);
    return ans;
  }
  inline long long kth(long long k) {
    long long x = 0, sum = 0, lg = log(n) / log(2);
    for (long long i = lg; i >= 0; i--) {
      if (sh[x + (1 << i)] < k) {
        k -= sh[x + (1 << i)];
        x += (1 << i);
      }
    }
    return x + 1;
  }
} T;
void prework() {
  n = 400000;
  fac[0] = 1;
  for (long long i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % 998244353;
  inv[n] = m_pow(fac[n], 998244353 - 2);
  for (long long i = n - 1; i >= 0; i--)
    inv[i] = inv[i + 1] * (i + 1) % 998244353;
  for (long long i = 1; i <= n / 2; i++) T.change(i, 1);
}
signed main() {
  prework();
  t = read();
  while (t--) {
    n = read();
    m = read();
    for (long long i = 1; i <= m; i++) x[i] = read(), y[i] = read();
    long long k = 0;
    for (long long i = m; i >= 1; i--) {
      pos[i] = T.kth(y[i]);
      if (T.query(pos[i] + 1) > y[i]) k++;
      T.change(pos[i], -1);
    }
    printf("%lld\n", C(2 * n - k - 1, n));
    for (long long i = 1; i <= m; i++) T.change(pos[i], 1);
  }
}
