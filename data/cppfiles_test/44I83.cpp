#include <bits/stdc++.h>
using namespace std;
long long a[5000007], b[5000007], c[5000007];
long long mod = 1e9 + 7;
long long power(long long x, long long y, long long p) {
  long long res = 1;
  x = x % p;
  if (x == 0) return 0;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
void SieveOfEratosthenes(long long n) {
  bool prime[n + 1];
  long long j = 0;
  memset(prime, true, sizeof(prime));
  for (long long p = 2; p * p <= n; p++) {
    if (prime[p] == true) {
      for (long long i = p * p; i <= n; i += p) prime[i] = false;
    }
  }
  for (long long p = 2; p <= n; p++)
    if (prime[p]) prime[j++] = p;
}
bool isPrime(long long n) {
  if (n <= 1) return false;
  for (long long i = 2; i < n; i++)
    if (n % i == 0) return false;
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  while (t--) {
    long long n, i, j, m, k, x, flag = 1;
    std::map<long long, long long> mp1;
    cin >> n >> m;
    if (n == m && n == 0)
      cout << "0\n";
    else if (abs(n - m) == 1)
      cout << "-1\n";
    else if (n == m)
      cout << "1\n";
    else
      cout << "2\n";
  }
  return 0;
}
