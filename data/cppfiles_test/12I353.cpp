#include <bits/stdc++.h>
using namespace std;
const long long inf = LLONG_MAX, MOD = 1e9 + 7, md = 998244353;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
long long add(long long a, long long b) {
  return ((a % MOD) + (b % MOD)) % MOD;
}
long long multi(long long a, long long b) {
  return ((a % MOD) * (b % MOD)) % MOD;
}
long long sub(long long a, long long b) {
  a %= MOD;
  b %= MOD;
  a -= b;
  if (a < 0) a += MOD;
  return a;
}
long long _max(long long x, long long y) { return (x > y) ? x : y; }
long long _min(long long x, long long y) { return (x < y) ? x : y; }
long long _abs(long long x) { return (x >= 0) ? x : (-1 * x); }
long long power(long long a, long long b) {
  a %= MOD;
  long long res = 1;
  while (b > 0) {
    if (b & 1) {
      res = multi(res, a);
    }
    a = multi(a, a);
    b >>= 1;
  }
  return res;
}
bool isPrime(long long x) {
  if (x <= 4 || x % 2 == 0 || x % 3 == 0) {
    return x == 2 || x == 3;
  }
  for (int i = 5; i * i <= x; i += 6) {
    if (x % i == 0 || x % (i + 2) == 0) {
      return false;
    }
  }
  return true;
}
const long long mx = 1e6 + 5;
void solve() {
  long long n, m, k;
  cin >> n >> m >> k;
  if ((n % 2) == 0 && (m % 2) == 0) {
    if ((k % 2) == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  } else if (n % 2 == 0) {
    if ((k % 2) == 0 && k <= ((n * (m - 1)) / 2))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  } else if (m % 2 == 0) {
    if ((k % (m / 2) == 0) && ((k / (m / 2)) % 2 != 0))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
int main() {
  long long tn = 1;
  cin >> tn;
  for (long long test = 1; test < tn + 1; test++) solve();
  return 0;
}
