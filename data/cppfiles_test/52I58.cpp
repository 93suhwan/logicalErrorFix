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
long long fastPowerMod(long long a, long long b, long long m) {
  if (b == 1)
    return a;
  else if (b % 2 == 0)
    return fastPowerMod((a % m) * (a % m), b / 2, m) % m;
  else
    return ((fastPowerMod((a % m) * (a % m), b / 2, m) % m) * (a % m)) % m;
}
int main() {
  long long t, n, m;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    long long com, f, ans = 0;
    do {
      com = log2(m);
      f = fastPower(2, com);
      ans += fastPower(n, com);
      m -= f;
    } while (m - f != 0);
    cout << ans % mod << "\n";
  }
}
