#include <bits/stdc++.h>
using namespace std;
long long MOD = 1e9 + 7;
long long fact[200010];
long long extEuclid(long long a, long long b, long long &x, long long &y) {
  long long xx = y = 0;
  long long yy = x = 1;
  while (b) {
    long long q = a / b;
    tie(a, b) = make_tuple(b, a % b);
    tie(x, xx) = make_tuple(xx, x - q * xx);
    tie(y, yy) = make_tuple(yy, y - q * yy);
  }
  return a;
}
long long modInverse(long long b, long long m) {
  long long x, y;
  long long d = extEuclid(b, m, x, y);
  if (d != 1) return -1;
  return (x + m) % m;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  fact[0] = 1;
  for (int i = 1; i < 200010; i++) fact[i] = (i * fact[i - 1]) % MOD;
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    int m = n / 2 + 1;
    long long A[m + 10];
    for (int i = 0; i < m; i++) {
      int p = 2 * i;
      A[i] = fact[n] * modInverse(fact[p], MOD);
      A[i] %= MOD;
      A[i] *= modInverse(fact[n - p], MOD);
      A[i] %= MOD;
    }
    if (n % 2) {
      m++;
      A[m - 1] = 1;
    }
    long long t = 0;
    for (int i = 0; i < m; i++) {
      t += A[i];
      t %= MOD;
    }
    long long ans = t;
    for (int i = 1; i < k; i++) {
      ans *= t;
      ans %= MOD;
    }
    cout << ans << endl;
  }
  return 0;
}
