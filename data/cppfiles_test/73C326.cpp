#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
using namespace std;
long long M = 1e9 + 7;
long long mod(long long x) { return ((x % M + M) % M); }
long long gcd(long long a, long long b);
long long lcm(long long a, long long b);
bool prime(long long n);
long long BinExp(long long base, long long power);
long long ModInverse(long long base);
long long nCr(long long n, long long r);
long long fact(long long n) { return (n <= 1) ? 1 : n * fact(n - 1); }
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n), b;
  for (auto &x : a) cin >> x;
  long long ans = 0;
  b = a;
  sort(b.begin(), b.end());
  long long x = 0;
  while (b != a) {
    if (x == 0) {
      for (long long i = 0; i < n - 1; i += 2)
        if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);
    } else {
      for (long long i = 1; i < n - 1; i += 2)
        if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);
    }
    x = 1 - x;
    ans++;
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) solve();
}
long long nCr(long long n, long long r) {
  r = (n - r <= r) ? n - r : r;
  long long ans = 1;
  for (long long i = 0; i < r; i++) {
    ans *= (n - i);
    ans /= (i + 1);
  }
  return ans;
}
long long gcd(long long a, long long b) {
  if (a == 0) return b;
  return (a == 1) ? a : gcd(b % a, a);
}
long long lcm(long long a, long long b) { return (a / gcd(a, b)) * b; }
bool prime(long long n) {
  if (n < 2) return false;
  for (long long i = 2; i <= sqrt(n); i++)
    if (n % i == 0) return false;
  return true;
}
long long BinExp(long long base, long long power) {
  if (!power) return 1;
  long long res = 1;
  while (power > 1) {
    if (power % 2) {
      power--;
      res *= base;
    } else {
      base *= base;
      power /= 2;
    }
  }
  return base * res;
}
long long ModInverse(long long base) {
  long long power = M - 2;
  if (!power) return 1;
  long long res = 1;
  while (power > 1) {
    if (power % 2) {
      power--;
      res = mod(res * base);
    } else {
      base = mod(base * base);
      power /= 2;
    }
  }
  return mod(base * res);
}
