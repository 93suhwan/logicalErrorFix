#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353, siz = 1e6 + 5;
long long t, n, m, k, a[siz], fact[siz], dp[siz];
long long add(long long x, long long y) {
  x += y;
  x %= mod;
  return x;
}
long long sub(long long x, long long y) {
  x -= y;
  x += mod;
  x %= mod;
  return x;
}
long long mul(long long x, long long y) {
  x *= y;
  x %= mod;
  return x;
}
long long bix(long long a, long long n) {
  long long ret = 1;
  while (n > 0) {
    if (n & 1) (ret *= a) %= mod;
    (a *= a) %= mod;
    n /= 2;
  }
  return ret;
}
long long div(long long x) {
  long long ret = bix(x, mod - 2);
  return ret;
}
void pre() {
  fact[0] = 1;
  for (long long i = 1; i < siz; i++) fact[i] = (fact[i - 1] * i) % mod;
}
long long ncr(long long n, long long r) {
  if (r > n or n < 0) return 0;
  if (n == 0 and r == 0) return 1;
  long long ret = fact[n];
  (ret *= bix(fact[r], mod - 2)) %= mod;
  (ret *= bix(fact[n - r], mod - 2)) %= mod;
  return ret;
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  pre();
  cin >> n >> k;
  string s;
  cin >> s;
  long long ones = 0;
  for (long long i = 1; i <= n; i++) {
    a[i] = s[i - 1] - '0';
    ones += a[i];
  }
  if (k < 1 or k > ones) return cout << 1 << endl, 0;
  bool first_chunk = 1;
  ones = 0;
  for (long long i = 1; i <= n; i++) {
    ones += a[i];
    if (ones < k) continue;
    long long cur = 0, stops = i;
    for (long long j = i; j >= 1; j--) {
      cur += a[j];
      if (cur > k) break;
      stops = j;
    }
    long long len = i - stops + 1;
    if (first_chunk) {
      dp[i] = ncr(len, k);
      first_chunk = 0;
    } else {
      if (a[i]) {
        dp[i] += dp[i - 1];
        dp[i] += ncr(len - 1, k);
        dp[i] %= mod;
      } else {
        dp[i] += dp[i - 1];
        dp[i] += ncr(len - 1, k - 1);
        dp[i] %= mod;
      }
    }
  }
  cout << dp[n] << endl;
}
