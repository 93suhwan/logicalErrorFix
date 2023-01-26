#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long m1 = 1000000123;
const long long m2 = 1000000321;
inline long long modMul(long long a, long long b) {
  return ((a % mod) * (b % mod)) % mod;
}
inline long long modAdd(long long a, long long b) {
  return ((a % mod) + (b % mod)) % mod;
}
inline long long modPow(long long b, long long p) {
  long long r = 1;
  while (p) {
    if (p & 1) r = modMul(r, b);
    b = modMul(b, b);
    p >>= 1;
  }
  return r;
}
inline long long modInverse(long long a) { return modPow(a, mod - 2); }
inline long long modDiv(long long a, long long b) {
  return modMul(a, modInverse(b));
}
long long const maxn = 1000000 + 1;
long long fact[1000006];
long long inv[1000006];
long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
bool comp(long long a, long long b) { return a > b; }
long long power(long long a, long long n) {
  long long res = 1;
  while (n) {
    if (n % 2 == 0) {
      a = ((a) * (a));
      n = n / 2;
    } else {
      n--;
      res = ((a) * (res));
    }
  }
  return res;
}
void solve() {
  long long n;
  cin >> n;
  long long a = 0;
  long long b = 0;
  if (n % 3 == 0) {
    long long x = n / 3;
    cout << x << " " << x << "\n";
  } else {
    long long r = n % 3;
    a = n / 3;
    b = n / 3;
    if (r == 2) {
      b++;
    } else {
      a++;
    }
    cout << a << " ";
    ;
    cout << b << "\n";
    ;
  }
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long test;
  test = 1;
  cin >> test;
  while (test--) {
    solve();
  }
  return 0;
}
