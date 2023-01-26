#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
inline long long ksm(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
inline long long inv(long long x) { return ksm(x, mod - 2); }
long long t, n, m, rb, cb, rd, cd, p;
signed main() {
  ios::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n >> m >> rb >> cb >> rd >> cd >> p;
    p = (1 - p * inv(100) % mod + mod) % mod;
    long long dr = -1, dc = -1, u = 0, v = 1;
    for (long long i = 1; i <= 4 * (n - 1) * (m - 1); i++) {
      if (rb + dr < 1 || rb + dr > n) dr = -dr;
      if (cb + dc < 1 || cb + dc > m) dc = -dc;
      rb += dr;
      cb += dc;
      u = (u + 1) % mod;
      if (rb == rd || cb == cd) {
        u = u * p % mod;
        v = v * p % mod;
      }
    }
    v = (1 - v + mod) % mod;
    printf("%lld\n", u * inv(v) % mod);
  }
}
