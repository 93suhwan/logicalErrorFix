#include <bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
using namespace std;
const long long inf = 1e9 + 228;
const long long infll = 1e18;
const long long mod = 1e9 + 7;
const long double eps = 1e-5;
const long long mod2 = 998244353;
const long double PI = atan2l(0, -1);
void fast_io() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
long long binpow(long long n, long long k) {
  if (!k) return 1;
  if (k & 1) return binpow(n, k - 1) * n % mod;
  long long b = binpow(n, k / 2);
  return b * b % mod;
}
void solve() {
  long long n, m, k, r, c;
  cin >> n >> m >> k >> r >> c;
  long long a, b, cc, d;
  cin >> a >> b >> cc >> d;
  if (a == cc && b == d) {
    cout << binpow(k, n * m) << '\n';
  } else {
    cout << binpow(k, n * m - r * c) << '\n';
  }
}
signed main() {
  fast_io();
  long long q = 1;
  while (q--) solve();
  return 0;
}
