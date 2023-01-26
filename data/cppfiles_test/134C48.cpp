#include <bits/stdc++.h>
long double pi = acos(-1.0);
const int mod = 998244353;
using namespace std;
long long add(long long x, long long y) { return (x % mod + y % mod) % mod; }
long long sub(long long x, long long y) { return (x % mod - y % mod) % mod; }
long long mul(long long x, long long y) {
  return ((x % mod) * (y % mod)) % mod;
}
long long binpow(long long a, long long n) {
  if (n == 0) return 1;
  if (n % 2 == 1) {
    long long b = binpow(a, n - 1ll);
    return mul(b, a);
  } else {
    long long b = binpow(a, n / 2ll);
    return mul(b, b);
  }
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout.precision(10);
  cout.setf(ios::fixed);
  int t;
  cin >> t;
  for (int(tt) = 0; (tt) < t; (tt)++) {
    int n;
    cin >> n;
    vector<long long> v(n);
    for (int(i) = 0; (i) < n; (i)++) cin >> v[i];
    long long g = v[0];
    for (int i = 2; i < n; i += 2) {
      g = gcd(g, v[i]);
    }
    int k = 1;
    for (int i = 1; i < n; i += 2) {
      if (v[i] % g == 0) k = 0;
    }
    if (k) {
      cout << g << '\n';
      continue;
    }
    g = v[1];
    for (int i = 1; i < n; i += 2) {
      g = gcd(g, v[i]);
    }
    k = 1;
    for (int i = 0; i < n; i += 2) {
      if (v[i] % g == 0) k = 0;
    }
    if (k) {
      cout << g << '\n';
    } else
      cout << 0 << '\n';
  }
  return 0;
}
