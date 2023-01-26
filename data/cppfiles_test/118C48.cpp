#include <bits/stdc++.h>
using namespace std;
const long long maxn = 250005, p = 998244353;
long long n, deg[maxn], fac[maxn];
inline long long FP(long long b, long long k) {
  long long ret = 1, mul = b;
  while (k) {
    if (k & 1) ret = ret * mul % p;
    mul = mul * mul % p;
    k >>= 1;
  }
  return ret;
}
vector<long long> r;
vector<long long> dft(vector<long long> a, long long l) {
  r.resize(l);
  for (long long al = 1; al < l; al <<= 1)
    for (long long be = 0; be < al; be++) r[al + be] = r[be] + l / al / 2;
  for (long long al = 0; al < l; al++)
    if (r[al] > al) swap(a[al], a[r[al]]);
  for (long long al = 1; al < l; al <<= 1) {
    long long w = FP(3, (p - 1) / al / 2);
    for (long long be = 0; be < l; be += (al << 1))
      for (long long ga = 0, wn = 1; ga < al; ga++, wn = wn * w % p) {
        long long fr = a[be + ga];
        a[be + ga] = (a[be + ga] + wn * a[al + be + ga]) % p;
        a[al + be + ga] = (fr + (p - wn) * a[al + be + ga]) % p;
      }
  }
  return a;
}
vector<long long> operator*(vector<long long> a, vector<long long> b) {
  long long re = a.size() + b.size() - 1, l = 1;
  while (l < re) l <<= 1;
  a.resize(l), b.resize(l);
  a = dft(a, l), b = dft(b, l);
  for (long long al = 0; al < l; al++) a[al] *= b[al], a[al] %= p;
  reverse(a.begin() + 1, a.end());
  a = dft(a, l);
  long long inv = FP(l, p - 2);
  for (long long al = 0; al < l; al++) a[al] *= inv, a[al] %= p;
  a.resize(re);
  return a;
}
vector<long long> solve(long long a, long long b) {
  if (a == b) {
    vector<long long> ret;
    ret.resize(2);
    ret[0] = 1, ret[1] = deg[a];
    return ret;
  }
  return solve(a, (a + b) >> 1) * solve(((a + b) >> 1) + 1, b);
}
signed main() {
  scanf("%lld", &n);
  for (long long al = 1, be, ga; al < n; al++)
    scanf("%lld%lld", &be, &ga), ++deg[be], ++deg[ga];
  for (long long al = 2; al <= n; al++) --deg[al];
  vector<long long> ans = solve(1, n);
  long long otp = 0;
  fac[0] = 1;
  for (long long al = 1; al <= n; al++) fac[al] = fac[al - 1] * al % p;
  for (long long al = 0, mul = 1; al < n; al++, mul = -mul)
    otp = (otp + mul * fac[n - al] * ans[al] % p + p) % p;
  printf("%lld\n", otp);
  return 0;
}
