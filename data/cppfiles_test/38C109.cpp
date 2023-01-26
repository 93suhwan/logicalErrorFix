#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
long long int fac[1000005];
long long int modularExponentiation(long long int x, long long int n,
                                    long long int M) {
  long long int result = 1;
  while (n > 0) {
    if (n % 2 == 1)
      result = ((result % 1000000007ll) * (x % 1000000007ll)) % 1000000007ll;
    x = ((x % 1000000007ll) * (x % 1000000007ll)) % 1000000007ll;
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
  long long int n, m;
  cin >> n >> m;
  char c[n + 1][m + 1];
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 0; j < m; j++) cin >> c[i + 1][j + 1];
  }
  set<long long int> prob;
  for (long long int j = 1; j < m; j++) {
    for (long long int i = 2; i <= n; i++) {
      if (c[i][j] == 'X' && c[i - 1][j + 1] == 'X') {
        prob.insert(j);
        break;
      }
    }
  }
  long long int q, l, r;
  cin >> q;
  while (q--) {
    cin >> l >> r;
    auto it = prob.lower_bound(l);
    if (it != prob.end()) {
      long long int z = *it;
      if (z >= r)
        cout << "YES"
             << "\n";
      else
        cout << "NO"
             << "\n";
    } else
      cout << "YES"
           << "\n";
  }
}
