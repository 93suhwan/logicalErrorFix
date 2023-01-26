#include <bits/stdc++.h>
using namespace std;
const long long N = 200010, mod = 998244353;
string s[N];
long long n, fact[N], inv[N];
long long sw, sb;
long long C(long long n, long long m) {
  if (n < 0 || m < 0 || m > n) return 0;
  return fact[n] * inv[m] % mod * inv[n - m] % mod;
}
long long qpow(long long n, long long k) {
  long long ans = 1;
  while (k) {
    if (k & 1) {
      ans *= n;
      ans %= mod;
    }
    n *= n;
    n %= mod;
    k >>= 1;
  }
  return ans;
}
signed main() {
  ios::sync_with_stdio(0);
  fact[0] = inv[0] = 1;
  for (long long i = (1), _b = (200000); i <= _b; i++) {
    fact[i] = fact[i - 1] * i % mod;
    inv[i] = qpow(fact[i], mod - 2);
  }
  bool f = 0;
  cin >> n;
  for (long long i = (1), _b = (n); i <= _b; i++) cin >> s[i];
  for (long long i = (1), _b = (n); i <= _b; i++) {
    if (s[i][0] == 'W') sw++;
    if (s[i][0] == 'B') sb++;
    if (s[i][1] == 'W') sw++;
    if (s[i][1] == 'B') sb++;
    if (s[i][0] == s[i][1] && s[i][0] != '?') f = 1;
  }
  long long ans = C(2 * n - sw - sb, n - sw);
  if (f) {
    cout << ans << "\n";
    return 0;
  }
  long long dec = 1;
  for (long long i = (1), _b = (n); i <= _b; i++) {
    if (s[i][0] == '?' && s[i][1] == '?') dec = dec * 2 % mod;
  }
  ans = (ans - dec + mod) % mod;
  long long inc = 1;
  for (long long i = (1), _b = (n); i <= _b; i++) {
    if (s[i][0] == 'B' || s[i][1] == 'W') inc = 0;
  }
  ans = (ans + inc) % mod;
  inc = 1;
  for (long long i = (1), _b = (n); i <= _b; i++) {
    if (s[i][0] == 'W' || s[i][1] == 'B') inc = 0;
  }
  ans = (ans + inc) % mod;
  cout << ans << "\n";
  return 0;
}
