#include <bits/stdc++.h>
using namespace std;
constexpr int mod = (int)1e9 + 7;
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
long long binpow(long long a, long long b, long long mod) {
  long long res = 1;
  a %= mod;
  while (b > 0) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
long long binmul(long long a, long long b) {
  long long res = 0;
  a %= mod;
  while (b > 0) {
    if (b & 1) res = (res + a) % mod;
    a = (a + a) % mod;
    b >>= 1;
  }
  return res;
}
long long area(pair<long long, long long> a, pair<long long, long long> b,
               pair<long long, long long> c) {
  return abs(a.first * b.second + b.first * c.second + c.first * a.second -
             a.second * b.first - b.second * c.first - c.second * a.first);
}
long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }
long long min(long long a, long long b) {
  if (a < b) {
    return a;
  }
  return b;
}
long long max(long long a, long long b) {
  if (a > b) {
    return a;
  }
  return b;
}
double intlog(long long n, long long base) {
  return (double)log(n) / log(base);
}
long long t, m, temp, temp2, root, q, k, i, j, r, u, v, w, n, l, p;
int main() {
  cin >> t;
  while (t--) {
    cin >> n;
    vector<long long> dp1(n + 1, 0);
    vector<long long> dp2(n + 1, 0);
    for (i = 0; i < n; i++) {
      cin >> p;
      dp1[i + 1] = dp1[i] + p;
    }
    for (i = 0; i < n; i++) {
      cin >> p;
      dp2[i + 1] = dp2[i] + p;
    }
    long long res = LLONG_MAX;
    for (int i = 1; i <= n; i++) {
      res = min(res, max(dp2[i - 1], dp1[n] - dp1[i]));
    }
    cout << res << "\n";
  }
}
