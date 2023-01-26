#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long MAX = 1e6 + 1;
long double eps = 1e-9;
long long check(long long n) {
  for (long long i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) return 0;
  }
  return 1;
}
long long binaryexpo(long long a, long long b, long long p) {
  if (a == 0) return 0;
  a %= p;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % p;
    b >>= 1;
    a = (a * a) % p;
  }
  return res;
}
long long mul(long long a, long long b) { return (a * 1ll * b) % MOD; }
long long bpow(long long a, long long b) {
  if (b == 0) return 1;
  long long res = bpow(a, b / 2);
  if (b % 2)
    return res * res * a;
  else
    return res * res;
}
long long leftmost_set_bit(long long n) {
  long long l = 0, r = 63;
  long long ans = -1;
  while (l <= r) {
    long long mid = (l + r) / 2;
    if (1ll << mid <= n) {
      ans = mid;
      l = mid + 1;
    } else
      r = mid - 1;
  }
  return ans;
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, h;
    cin >> n >> h;
    long long a[n];
    for (long long i = 0; i < n; i++) cin >> a[i];
    long long lo = 1, hi = h, mid = 0, ans = 0;
    while (hi >= lo) {
      mid = lo + (hi - lo) / 2;
      long long sum = 0;
      for (long long i = 0; i < n - 1; i++) {
        long long temp = min(mid, a[i + 1] - a[i]);
        sum += temp;
      }
      sum += mid;
      if (sum >= h) {
        hi = mid - 1;
        ans = mid;
      } else
        lo = mid + 1;
    }
    cout << ans << "\n";
  }
}
