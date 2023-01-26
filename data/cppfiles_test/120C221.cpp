#include <bits/stdc++.h>
using namespace std;
long long mod = 1e9 + 7;
long long power1(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  if (b % 2 == 0)
    return (power1((a * a), b / 2));
  else
    return (power1((a * a), b / 2) * a);
}
long long power(long long a, long long b) {
  if (b == 0) return 1;
  if (b == 1) return a;
  if (b % 2 == 0)
    return (power((a * a) % mod, b / 2)) % mod;
  else
    return (power((a * a) % mod, b / 2) * a) % mod;
}
long long fact(long long n) {
  if (n == 0) return 1;
  if (n == 1) return 1;
  return (fact(n - 1) * n) % mod;
}
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
vector<bool> prime(1e7, true);
void sieve(long long n) {
  for (int p = 2; p * p <= n; p++) {
    if (prime[p]) {
      for (int i = p * 2; i <= n; i += p) prime[i] = false;
    }
  }
}
void swap(long long &a, long long &b) {
  long long t = b;
  b = a;
  a = t;
}
long long invmod(long long n) { return power(n, mod - 2); }
int main() {
  long long t;
  cin >> t;
  vector<vector<long long>> a(21, vector<long long>(2e5 + 1, 0));
  long long base = 1;
  for (long long i = 0; i < 21; i++) {
    for (long long j = 0; j < 2e5 + 1; j++) {
      if ((j / base) % 2 == 0) a[i][j]++;
      if (j > 0) a[i][j] += a[i][j - 1];
    }
    base *= 2;
  }
  for (; t > 0; t--) {
    long long l, r;
    cin >> l >> r;
    long long ans = INT_MAX;
    for (long long i = 0; i < 21; i++) {
      ans = min(ans, a[i][r] - a[i][l - 1]);
    }
    cout << ans << "\n";
  }
  return 0;
}
