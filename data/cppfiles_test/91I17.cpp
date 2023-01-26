#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const double eps = 1e-8;
namespace math_41 {
const int math_41_MOD = ::MOD;
template <typename T>
inline T ksc(T a, T b, T p = math_41_MOD) {
  long long ret = 0;
  for (; b; b >>= 1) {
    if (b & 1) ret = (ret + a) % p;
    a = a * 2 % p;
  }
  return ret;
}
template <typename T>
inline T multiplyy(T a, T b, T m) {
  T c = a * b - (T)((long double)a * b / m + 0.5) * m;
  return c < 0 ? c + m : c;
}
template <typename T>
inline T ksm(T a, T b, T p = math_41_MOD) {
  long long ret = 1 % p;
  for (; b; b >>= 1) {
    if (b & 1) ret = ret * a % p;
    a = a * a % p;
  }
  return ret;
  a %= p;
  if (b == 0) return 1 % p;
  if (b == 1) return a;
  return ksm(a * a, b / 2, p) * (b & 1 ? a : 1) % p;
}
template <typename T>
inline T inverse(T a, T p = math_41_MOD) {
  return ksm(a, p - 2, p);
}
template <typename long long>
long long exgcd(long long a, long long b, long long& x, long long& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long d = exgcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
}
long long CRT(int k, long long* a, long long* r, long long mod = MOD) {
  long long n = 1, ans = 0;
  for (int i = 1; i <= k; i++) n = n * r[i];
  for (int i = 1; i <= k; i++) {
    long long m = n / r[i], b, y;
    exgcd(m, r[i], b, y);
    ans = (ans + a[i] * m * b % mod) % mod;
  }
  return (ans % mod + mod) % mod;
}
}  // namespace math_41
using namespace math_41;
int main() {
  long long T = 1;
  scanf("%lld", &T);
  while (T--) {
    long long n, anss = 0;
    scanf("%lld", &n);
    vector<long long> a(n + 1), b(n + 1), c(n + 1), cb(n + 1);
    for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (long long bg = 1, i, las; bg <= n; bg++) {
      if (a[bg] >= a[bg - 1] && bg > 1)
        b[bg] = b[bg - 1];
      else {
        for (i = bg - 1, las = a[bg]; i; i--) {
          long long k = (a[i] - 1) / las + 1;
          las = a[i] / k;
          cb[i] = (k - 1) * (i) % MOD;
          if (c[i] <= las && c[i]) break;
          c[i] = las;
        }
        for (i += i == 0; i < bg; i++) {
          cb[i] += cb[i - 1];
        }
        b[bg] = cb[bg - 1];
      }
      anss += b[bg];
    }
    printf("%lld\n", anss);
  }
  return 0;
}
