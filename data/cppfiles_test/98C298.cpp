#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
vector<long long> fact(1);
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
long long power(long long x, long long y) {
  long long temp;
  if (y == 0) return 1;
  temp = power(x, y / 2);
  if (y % 2 == 0)
    return temp * temp;
  else
    return x * temp * temp;
}
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long modInv(long long n, long long p) { return power(n, p - 2, p); }
long long ncr(long long n, long long r) {
  return (n >= r ? (fact[n] * modInv(fact[r], mod)) % mod *
                       modInv(fact[n - r], mod) % mod
                 : 0);
}
long long add(long long a, long long b) {
  long long z = a + b;
  if (z >= mod) z -= mod;
  return z;
}
long long mul(long long a, long long b) { return (a * b) % mod; }
long long sub(long long a, long long b) { return (a - b + mod) % mod; }
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long tt = 1, p, i, j, n, k, m;
  cin >> tt;
  for (p = 1; p <= tt; p++) {
    cin >> n;
    string s;
    cin >> s;
    if (n == 1) {
      cout << -1 << ' ' << -1 << '\n';
      continue;
    }
    long long f = 0;
    for (i = 1; i < n; i++) {
      if (s[i] != s[i - 1]) {
        f = 1;
        cout << i << ' ' << i + 1 << '\n';
        break;
      }
    }
    if (f == 0) cout << -1 << ' ' << -1 << '\n';
  }
}
