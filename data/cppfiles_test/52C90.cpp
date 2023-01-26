#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long qpow(long long a, long long b, const long long p) {
  if (a == 0) return 0;
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % p;
    b >>= 1;
    a = a * a % p;
  }
  return res;
}
signed main(void) {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long ans = 0;
    while (k) {
      long long te = k & (-k);
      ans = (ans + qpow(n, (int)log2(te), mod)) % mod;
      k -= te;
    }
    cout << ans << '\n';
  }
  return 0;
}
