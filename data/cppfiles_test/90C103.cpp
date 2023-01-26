#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long inv(long long i) {
  if (i == 1) return 1;
  return (mod - ((mod / i) * inv(mod % i)) % mod) % mod;
}
long long mod_mul(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (((a * b) % mod) + mod) % mod;
}
long long mod_add(long long a, long long b) {
  a = a % mod;
  b = b % mod;
  return (((a + b) % mod) + mod) % mod;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long ceil_div(long long a, long long b) {
  return a % b == 0 ? a / b : a / b + 1;
}
long long pwr(long long a, long long b) {
  a %= mod;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return res;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t, n, i, j, ans, temp, sum, x, y;
  string sans;
  t = 1;
  cin >> t;
  while (t--) {
    sans = "NO";
    ans = temp = sum = 0;
    cin >> x >> y;
    if (x > y) {
      ans = (x + y);
    } else if (3 * x > y) {
      ans = (x + y) / 2;
    } else {
      long long k1 =
          (y - 2 * x) % x == 0 ? (y - 2 * x) / x + 1 : ceil_div(y - 2 * x, x);
      ans = (k1 * x + y) / 2;
    }
    cout << ans << "\n";
  }
  return 0;
}
