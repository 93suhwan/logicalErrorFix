#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long n, m, a, b, c, d, p, e, f;
long long qpw(long long a, long long b) {
  long long res = 1;
  a %= mod;
  while (b) {
    if (b & 1) res = res * a % mod;
    b >>= 1;
    a = a * a % mod;
  }
  return res;
}
long long inv(long long x) { return qpw(x, mod - 2); }
void solve() {
  cin >> a >> b >> c >> d >> e >> f >> p;
  long long k1 = 1, k2 = 1;
  long long ans = 0;
  vector<long long> v(1, 0);
  long long tot = 0;
  if (c + k1 == a + 1 || c + k1 == 0) k1 *= -1;
  if (d + k2 == b + 1 || d + k2 == 0) k2 *= -1;
  auto state = make_tuple(c, d, k1, k2);
  while (1) {
    v.push_back(v.back() + (c == e || d == f));
    c += k1, d += k2;
    tot++;
    if (c + k1 == a + 1 || c + k1 == 0) k1 *= -1;
    if (d + k2 == b + 1 || d + k2 == 0) k2 *= -1;
    if (state == make_tuple(c, d, k1, k2)) {
      long long T = tot;
      long long q = qpw((100 - p) * inv(100), v.back());
      for (long long i = 0; i < T; i++) {
        long long pi =
            qpw((100 - p) * inv(100), v[i]) * (p * inv(100) % mod) % mod;
        if (v[i + 1] == v[i]) pi = 0;
        ans += pi * (((T * q) - i * q + i) % mod) % mod *
               inv((mod + 1 - q) * (mod + 1 - q)) % mod;
      }
      cout << (ans % mod + mod) % mod << "\n";
      return;
    }
  }
}
signed main() {
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
