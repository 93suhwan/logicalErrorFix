#include <bits/stdc++.h>
using namespace std;
long long int mod = 1e9 + 7;
long long int mxm = 1e18;
long long int fac(long long int n, long long int mod) {
  if (n >= mod) {
    return 0;
  }
  long long int res = 1;
  for (long long int i = 1; i <= n; i++) {
    res = (res * i) % mod;
  }
  return res;
}
long long int modInverse(long long int a, long long int m) {
  for (long long int x = 1; x < m; x++)
    if (((a % m) * (x % m)) % m == 1) return x;
}
long long int power(long long int x, long long int y, long long int p) {
  long long int res = 1;
  x = x % p;
  while (y > 0) {
    if (y & 1) res = (res * x) % p;
    y = y >> 1;
    x = (x * x) % p;
  }
  return res;
}
long long int modi(long long int n, long long int p) {
  return power(n, p - 2, p);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    long long int mx = 2 * n;
    long long int x = fac(mx, mod);
    cout << ((x * modi(2, mod)) % mod) << endl;
  }
  return 0;
}
