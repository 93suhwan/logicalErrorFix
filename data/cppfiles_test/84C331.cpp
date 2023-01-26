#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
using namespace std;
long long mod = 1000000007;
inline long long add(long long a, long long b) {
  return ((a % mod) + (b % mod) + mod) % mod;
}
inline long long mul(long long a, long long b) {
  return (((a % mod) * (b % mod)) % mod + mod) % mod;
}
inline long long sub(long long a, long long b) {
  return ((a % mod) - (b % mod) + mod) % mod;
}
int N = 2e5 + 5;
int GCD(int a, int b) {
  if (b == 0) return a;
  return GCD(b, a % b);
}
int prod(int a, int b) {
  int res = 0;
  a %= mod;
  while (b) {
    if (b & 1ll) res = (res + a) % mod;
    a = (2ll * a) % mod;
    b >>= 1ll;
  }
  return res;
}
int power(int a, int b) {
  int res = 1ll;
  while (b > 0) {
    if (b % 2ll) res = (res * a) % mod;
    a = (a * a) % mod;
    b /= 2ll;
  }
  return res;
}
long long binaryExponentiation(long long a, long long b) {
  long long result = 1ll;
  while (b > 0) {
    if (b % 2 == 1) result = (result * a) % mod;
    a = (a * a) % mod;
    b /= 2ll;
  }
  return result;
}
long long ModularInverse(long long a) {
  return binaryExponentiation(a, mod - 2);
}
int fact(int n) {
  int res = 1;
  for (int i = 2; i <= n; i++) {
    res = (res * i) % mod;
  }
  return res % mod;
}
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
bool isprime(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) return false;
  }
  return true;
}
int isPrime(int n) {
  if (n < 2) return 0;
  if (n < 4) return 1;
  if (n % 2 == 0 or n % 3 == 0) return 0;
  for (int i = 5; i * i <= n; i += 6)
    if (n % i == 0 or n % (i + 2) == 0) return 0;
  return 1;
}
void solve() {
  long long n, s;
  cin >> n >> s;
  if (n == 1 && s == 1) {
    cout << 1 << "\n";
    return;
  } else if (n == 1) {
    cout << s << "\n";
    return;
  } else if (s == 1) {
    cout << 0 << "\n";
    return;
  } else {
    int medind;
    if (n % 2 != 0)
      medind = (n / 2) + 1;
    else
      medind = n / 2;
    int len = n - medind + 1;
    if (s >= len) {
      cout << (s / len) << "\n";
      return;
    } else {
      cout << 0 << "\n";
      return;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
