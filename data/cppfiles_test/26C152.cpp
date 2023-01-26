#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long mod_mul(long long x, long long y, int p) { return (x * 1 * y) % p; }
long long mod_pow(long long a, long long b, long long p) {
  a %= p;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = (res * a) % p;
    a = (a * a) % p;
    b >>= 1;
  }
  return res % p;
}
long long mod_div(long long a, long long b, long long p) {
  b = mod_pow(b, p - 2, p);
  a = mod_mul(a, b, p);
  return a;
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, i;
    cin >> n;
    long long int x = 1, y = 1000000007;
    for (i = 2; i <= (2 * n); i++) {
      x %= y;
      x *= (i % y);
      x %= y;
    }
    x = mod_div(x, 2, mod);
    cout << x << "\n";
  }
  return 0;
}
