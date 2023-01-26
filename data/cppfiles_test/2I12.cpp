#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
const long long mod = 1000000007;
const long double pi = acos(-1);
struct complex {
  long double r, i;
  inline complex operator+(const complex& x) const {
    return {r + x.r, i + x.i};
  }
  inline complex operator-(const complex& x) const {
    return {r - x.r, i - x.i};
  }
  inline complex operator*(const complex& x) const {
    return {r * x.r - i * x.i, r * x.i + i * x.r};
  }
};
complex c[maxn << 2];
inline void fft(const int&, complex*, const bool&);
int t[maxn << 2];
long long b[maxn], B[2][maxn];
int a[maxn], s[maxn];
long long v[maxn];
int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  if (k == 1) {
    long long cnt = (long long)n * m % mod;
    printf("%lld\n", ((cnt * (cnt + 1) + ((cnt - 1) * (cnt - 1) << 1) -
                       cnt * (cnt - 1)) >>
                      1) %
                         mod);
  }
  int l = 1;
  while (l <= k) l <<= 1;
  l <<= 1;
  for (int i = 0; i < l; i++) t[i] = (t[i >> 1] >> 1) | ((i & 1) ? l >> 1 : 0);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    s[i] = (s[i - 1] + a[i]) % k;
  }
  long long ans = 0;
  b[0]++;
  for (int i = 1; i <= n; i++) ans += (long long)b[s[i]] * m, b[s[i]]++;
  ans %= mod;
  memset(b, 0, sizeof(b)), b[0]++;
  for (int i = 1; i <= n; i++)
    ans += (long long)b[s[i]] * m, b[(s[i] + (long long)s[n] * m) % k]++;
  ans %= mod;
  if (m != 1) {
    int S = 0;
    for (int i = 1; i <= n; i++) B[0][S = (S + a[i]) % k]++;
    S = 0;
    for (int i = n; i; i--) B[1][S = (S + a[i]) % k]++;
    for (int i = 0; i < k; i++)
      c[i] = {(long double)B[0][i], (long double)B[1][i]};
    fft(l, c, true);
    for (int i = 0; i < l; i++) c[i] = c[i] * c[i];
    fft(l, c, false);
    for (int i = 0; i < l; i++)
      v[i % k] = (v[i % k] + (long long)roundl(c[i].i / 2)) % mod;
    for (int i = 0; i <= m - 2; i++)
      ans = (ans + v[(k - i * s[n] % k) % k] * m) % mod;
    for (int i = 0; i < m; i++)
      ans -= (B[0][(k - i * s[n] % k) % k] + B[1][(k - i * s[n] % k) % k]);
    if (!(m * s[n] % k)) ans++;
    ans = (ans % mod + mod) % mod;
  } else {
    int S = 0;
    for (int i = 1; i <= n; i++) B[0][S = (S + a[i]) % k]++;
    S = 0;
    for (int i = n; i; i--) B[1][S = (S + a[i]) % k]++;
    for (int i = 0; i < m; i++) {
      ans -= (B[0][(k - i * s[n] % k) % k] + B[1][(k - i * s[n] % k) % k]);
      if (!(s[n] % k)) ans++;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
inline void fft(const int& l, complex* C, const bool& flag) {
  complex w, pow, tmp;
  for (int i = 0; i < l; i++)
    if (i < t[i]) tmp = C[i], C[i] = C[t[i]], C[t[i]] = tmp;
  for (int p = 2; p <= l; p <<= 1) {
    w = {cos(2 * pi / p), sin(2 * pi / p) * (flag ? 1 : -1)};
    for (int k = 0; k < l; k += p) {
      pow = {1, 0};
      for (int i = k; i < k + (p >> 1); i++) {
        tmp = pow * C[(p >> 1) + i];
        C[(p >> 1) + i] = C[i] - tmp, C[i] = C[i] + tmp;
        pow = pow * w;
      }
    }
  }
  if (!flag)
    for (int i = 0; i < l; i++) C[i].r /= l, C[i].i /= l;
  return;
}
