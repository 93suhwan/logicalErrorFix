#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
bool isEven(long long n);
bool isPrime(long long n);
long long power(long long a, long long b);
long long abmodm(long long a, long long b, long long m);
long long gcd(long long a, long long b);
long long lcm(long long a, long long b);
bool miller(long long n);
long long multiply(long long a, long long b, long long m);
long long extendedEuclid(long long a, long long b, long long& x, long long& y);
void solve() {
  long long n;
  cin >> n;
  string s;
  cin >> s;
  long long cnt = 0;
  for (long long i = 0; i < n - 2; i++) {
    if (s[i] == s[i + 1] && s[i] != s[i + 2]) {
      cnt++;
    }
  }
  cout << cnt << "\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
bool isEven(long long n) { return (!(n & 1)); }
bool isPrime(long long n) {
  long long cnt = 0;
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      cnt++;
      if (n / i != i) {
        cnt++;
      }
    }
  }
  return cnt == 2;
}
long long power(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
long long abmodm(long long a, long long b, long long m) {
  a %= m;
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % m;
    a = a * a % m;
    b >>= 1;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (!a || !b) return a | b;
  unsigned shift = __builtin_ctz(a | b);
  a >>= __builtin_ctz(a);
  do {
    b >>= __builtin_ctz(b);
    if (a > b) swap(a, b);
    b -= a;
  } while (b);
  return a << shift;
}
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
long long multiply(long long a, long long b, long long m) {
  long long result = 0;
  while (b > 0) {
    if (b & 1) {
      result = result + a;
      result %= m;
    }
    a <<= 1;
    a %= m;
    b >>= 1;
  }
  return result;
}
bool miller(long long n) {
  if (n <= 1 || n % 2 == 0) {
    if (n != 2) {
      return false;
    }
  }
  if (n == 2 || n == 3) {
    return true;
  }
  long long d = n - 1;
  while (d % 2 == 0) {
    d /= 2;
  }
  long long a[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
  for (long long i = 0; i < 12 && a[i] < n; ++i) {
    long long temp = d;
    long long mod = abmodm(a[i], temp, n);
    if (mod == 1) {
      continue;
    }
    while (temp != n - 1 && mod != n - 1) {
      mod = multiply(mod, mod, n);
      temp *= 2;
    }
    if (mod != n - 1) {
      return false;
    }
  }
  return true;
}
long long extendedEuclid(long long a, long long b, long long& x, long long& y) {
  x = 1, y = 0;
  long long x1 = 0, y1 = 1, a1 = a, b1 = b;
  while (b1) {
    long long q = a1 / b1;
    tie(x, x1) = make_tuple(x1, x - q * x1);
    tie(y, y1) = make_tuple(y1, y - q * y1);
    tie(a1, b1) = make_tuple(b1, a1 - q * b1);
  }
  return a1;
}
