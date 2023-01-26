#include <bits/stdc++.h>
const long long mod = 1000000000 + 7;
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long fastPower(long long a, long long b) {
  if (b == 0) return 1;
  long long value = fastPower(a, b / 2);
  if (b % 2 == 0)
    return value * value;
  else
    return value * value * a;
}
long long fastPowerMod(long long x, long long y, long long mod) {
  if (y == 0) return 1 % mod;
  long long u = fastPowerMod(x, y / 2, mod);
  u = u * u % mod;
  if (y & 1) u = u * x % mod;
  return u;
}
int main() {
  long long t, n, m;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    long long com, f, ans = 0;
    do {
      com = (long long)log2(m);
      f = fastPowerMod(2, com, mod);
      ans += fastPowerMod(n, com, mod);
      m -= f;
    } while (m != 0);
    cout << ans % mod << "\n";
  }
}
