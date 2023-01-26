#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
long long int fac[1000005];
long long int modularExponentiation(long long int x, long long int n,
                                    long long int M) {
  long long int result = 1;
  while (n > 0) {
    if (n % 2 == 1)
      result = ((result % 998244353ll) * (x % 998244353ll)) % 998244353ll;
    x = ((x % 998244353ll) * (x % 998244353ll)) % 998244353ll;
    n = n / 2;
  }
  return result;
}
long long int binaryExponentiation(long long int x, long long int n) {
  long long int result = 1.0;
  while (n > 0) {
    if (n % 2 == 1) result = result * x;
    x = x * x;
    n = n / 2;
  }
  return result;
}
long long int pow1(long long int x, long long int y) {
  long long int z = 1;
  while (y--) {
    z = z * x;
  }
  return z;
}
bool isprime(long long int n) {
  if (n <= 1) return false;
  if (n <= 3) return true;
  if (n % 2 == 0 || n % 3 == 0) return false;
  for (long long int i = 5; i * i <= n; i = i + 6)
    if (n % i == 0 || n % (i + 2) == 0) return false;
  return true;
}
long long int modInverse(long long int n, long long int p) {
  return modularExponentiation(n, p - 2, p);
}
long long int nCrModPFermat(long long int n, long long int r, long long int p) {
  if (r == 0) return 1;
  return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) %
         p;
}
long long int check(long long int x, long long int y) {
  long long int z = 1;
  long long int ans = 0;
  while (z < x) {
    ans++;
    z *= y;
  }
  return ans;
}
long long int countbits(long long int n) {
  long long int x = 0;
  while (n > 0) {
    x++;
    n = (n & (n - 1));
  }
  return x;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t, n, m, k;
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    long long int r = n % m;
    if (r == 0) {
      long long int x = n / m;
      long long int p = 1;
      for (long long int j1 = 1; j1 <= k; j1++) {
        for (long long int j = 1; j <= m; j++) {
          cout << x << ' ';
          for (long long int z = 1; z <= x; z++) {
            cout << p << ' ';
            p++;
            if (p > n) {
              p = 1;
            }
          }
          cout << "\n";
        }
      }
    } else {
      long long int x = n / m;
      long long int p = 1;
      for (long long int j1 = 1; j1 <= k; j1++) {
        vector<long long int> v[m];
        for (long long int z = 1; z <= r; z++) {
          long long int T = x + 1;
          while (T--) {
            v[z - 1].push_back(p++);
            if (p > n) p = 1;
          }
        }
        long long int p1 = p;
        for (long long int j = r + 1; j <= m; j++) {
          for (long long int z = 1; z <= x; z++) {
            v[j - 1].push_back(p1++);
            if (p1 > n) p1 = 1;
          }
        }
        for (long long int j = 1; j <= m; j++) {
          cout << v[j - 1].size() << ' ';
          for (auto z : v[j - 1]) cout << z << ' ';
          cout << "\n";
        }
      }
    }
    cout << "\n";
  }
}
