#include <bits/stdc++.h>
using namespace std;
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long T = 1;
  ;
  while (T--) {
    long long n;
    cin >> n;
    long long ans = 6;
    long long pow = 2;
    long long mod = 1000000007;
    for (long long i = 1; i < n; i++) {
      ans *= power(4, pow, mod);
      ans %= mod;
      pow *= 2;
    }
    cout << ans << endl;
  }
}
