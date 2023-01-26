#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lg(long long x) { return __builtin_clzll(1ll) - __builtin_clzll(x); }
long long vlg(long long x) { return 1ll << lg(x); }
void google() {
  static long long _gtest_ = 1;
  cout << "Case #" << _gtest_++ << ": ";
}
const long long mod = 998244353;
long long powm(long long a, long long n, long long p = mod) {
  long long res = 1;
  while (n) {
    if (n % 2) {
      res = (res * a) % p;
      n--;
    } else {
      a = (a * a) % p;
      n /= 2;
    }
  }
  return res;
}
void solve() {
  long long x, y;
  cin >> x >> y;
  if (x == y) {
    cout << x << '\n';
  } else if (x > y) {
    cout << x + y << '\n';
  } else {
    long long a = (y - x - 1);
    long long b = a / x;
    x += b * x;
    cout << (x + y) / 2 << '\n';
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
