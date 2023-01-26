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
  long long int t, n;
  string a, b;
  cin >> t;
  while (t--) {
    cin >> n >> a >> b;
    long long int a0 = 0, a1 = 0, b0 = 0, b1 = 0;
    long long int c01 = 0, c10 = 0, c00 = 0, c11 = 0;
    for (long long int i = 0; i < n; i++) {
      if (a[i] == '1')
        a1++;
      else
        a0++;
      if (b[i] == '1')
        b1++;
      else
        b0++;
      if (a[i] == '0' && b[i] == '1') c01++;
      if (a[i] == '1' && b[i] == '0') c10++;
      if (a[i] == '0' && b[i] == '0') c00++;
      if (a[i] == '1' && b[i] == '1') c11++;
    }
    long long int pos = 0;
    long long int mn = -1;
    if (a0 == b0 && a1 == b1) {
      pos = 1;
      mn = 2 * max(c01, c10);
    }
    if (b0 == (a1 - 1) && b1 == (a0 + 1)) {
      long long int z = n + 1;
      for (long long int i = 0; i < n; i++) {
        if (b[i] == '1') {
          long long int cc01 = c00;
          long long int cc10 = c11;
          if (a[i] == '1') cc10--;
          z = min(z, 2 * max(cc01, cc10) + 1);
        }
      }
      pos = 1;
      if (mn != -1)
        mn = min(mn, z);
      else
        mn = z;
    }
    if (pos)
      cout << mn << "\n";
    else
      cout << -1 << "\n";
  }
}
