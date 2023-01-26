#include <bits/stdc++.h>
long long gcd(long long m, long long n) { return n == 0 ? m : gcd(n, m % n); }
long long lcm(long long m, long long n) { return m * n / gcd(m, n); }
long long pows(long long base, long long power, long long mod) {
  long long result = 1;
  while (power > 0) {
    if (power & 1) {
      result = result * base % mod;
    }
    power >>= 1;
    base = (base * base) % mod;
  }
  return result;
}
long long poww(long long base, long long power) {
  long long result = 1;
  while (power > 0) {
    if (power & 1) {
      result = result * base;
    }
    power >>= 1;
    base = (base * base);
  }
  return result;
}
const long long inf = 1e18;
const int N = 2e5 + 10;
const int M = 400005 << 5;
const int C = 2e5 + 10;
const long long mod = 1e9 + 7;
using namespace std;
int main() {
  long long t;
  scanf("%lld", &t);
  while (t--) {
    long long n, m, k;
    scanf("%lld %lld %lld", &n, &m, &k);
    long long sm = (n * m) / 2, sx = sm - k;
    if (n % 2) {
      long long tt = m / 2;
      if (k % tt == 0 && (k / tt) % 2) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else if (m % 2) {
      long long tt = n / 2;
      if (sx % tt == 0 && (sx / tt) % 2) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    } else {
      if (k % 2 == 0 && sx % 2 == 0) {
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }
  }
  return 0;
}
