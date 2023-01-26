#include <bits/stdc++.h>
using namespace std;
void fileio() {}
long long gcd(long long a, long long b) { return (b) ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
long long max(long long a, long long b) { return (a >= b) ? a : b; }
long long min(long long a, long long b) { return (a <= b) ? a : b; }
long long pw(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) {
      res = res * a;
    }
    a = a * a;
    b = b >> 1;
  }
  return res;
}
long long pw(long long a, long long b, long long MOD) {
  long long res = 1;
  a %= MOD;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % MOD;
    }
    a = (a * a) % MOD;
    b = b >> 1;
  }
  return res;
}
long long egcd(long long a, long long b, long long& x, long long& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  long long x1, y1;
  long long _gcd = egcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - (y1 * (a / b));
  return _gcd;
}
long long modInv(long long a, long long MOD) {
  long long x, y;
  long long _gcd = egcd(a, MOD, x, y);
  if (_gcd != 1) {
    cout << "a and MOD are NOT coprime"
         << "\n";
    return -1;
  } else {
    return (x % MOD + MOD) % MOD;
  }
}
long long modInvFormat(long long a, long long MOD) {
  return pw(a, MOD - 2, MOD);
}
const long long inf = 1e18;
const long long ninf = -1e17;
const long long mod = 1e9 + 7;
const long long mod2 = 998244353;
void testcase(long long tc = 1) {
  vector<long long> v(7);
  for (long long i = 0; i < (long long)7; i++) cin >> v[i];
  long long a = v[0];
  long long b = v[1];
  long long c = v[6] - v[0] - v[1];
  cout << a << ' ' << b << ' ' << c << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long tcs = 1;
  fileio();
  cin >> tcs;
  for (long long tc = 1; tc <= tcs; tc++) {
    testcase(tc);
  }
  return 0;
}
