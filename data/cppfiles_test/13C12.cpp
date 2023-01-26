#include <bits/stdc++.h>
using namespace std;
using namespace chrono;
long long mod_add(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a + b) % m) + m) % m;
}
long long mod_mul(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a * b) % m) + m) % m;
}
long long mod_sub(long long a, long long b, long long m) {
  a = a % m;
  b = b % m;
  return (((a - b) % m) + m) % m;
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
long long modInverse(long long n, long long p) { return power(n, p - 2, p); }
long long nCrMODp(long long n, long long r, long long p) {
  if (n < r) return 0;
  if (r == 0) return 1;
  long long fac[n + 1];
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
void divisors(int n) {
  for (int i = 1; i <= sqrt(n); i++) {
    if (n % i == 0) {
      if (n / i == i)
        cout << " " << i;
      else
        cout << " " << i << " " << n / i;
    }
  }
}
void primeFactors(int n) {
  while (n % 2 == 0) {
    cout << 2 << " ";
    n = n / 2;
  }
  for (int i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      cout << i << " ";
      n = n / i;
    }
  }
  if (n > 2) cout << n << " ";
}
void solve() {
  int t;
  cin >> t;
  cin.ignore();
  while (t--) {
    int i, x = 0, y = 0;
    string str;
    cin >> str;
    for (i = 0; i < str.size(); i++) str[i] == 'B' ? x++ : y++;
    y == x ? cout << "YES\n" : cout << "NO\n";
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  auto start1 = high_resolution_clock::now();
  solve();
  auto stop1 = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop1 - start1);
  return 0;
}
