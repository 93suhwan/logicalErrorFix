#include <bits/stdc++.h>
using namespace std;
long long M1 = pow(10, 9) + 7, M2 = 998244353, NX = 9223372036854775807,
          LN = 1e18;
long long binpow(long long x, long long n) {
  long long res = 1;
  while (n) {
    if (n % 2) res = (res * x);
    n /= 2;
    x = (x * x);
  }
  return res;
}
long long modpow(long long x, long long n, long long M) {
  x = x % M;
  long long res = 1;
  while (n) {
    if (n % 2) res = (res * x) % M;
    n /= 2;
    x = (x * x) % M;
  }
  return res;
}
long long gcd(long long a, long long b) {
  if (!b) return a;
  return gcd(b, a % b);
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long tc = 1;
  cin >> tc;
  while (tc--) {
    long long n;
    cin >> n;
    long long i;
    vector<long long> a(n), b(n), c(n), d(n);
    for (i = 0; i < n; i++) cin >> b[i];
    if (n == 1) {
      cout << "YES\n";
      cout << b[0] << "\n";
      continue;
    }
    for (i = 0; i < n; i++) c[i] = b[i] - b[(i - 1 + n) % n];
    long long f = 0;
    for (i = 0; i < n; i++) {
      d[i] = c[i] - c[(i - 1 + n) % n];
      if (d[i] % n) f = 1;
      d[i] /= n;
    }
    if (f) {
      cout << "NO\n";
      continue;
    }
    a[0] = d[1] + 1;
    long long mi = a[0];
    for (i = 1; i < n; i++) {
      a[i] = a[i - 1] - d[i];
      mi = min(mi, a[i]);
    }
    if (mi <= 0)
      for (i = 0; i < n; i++) a[i] += 1 - mi;
    for (i = 0; i < n; i++) b[n - 1] -= (i + 1) * a[n - 1 - i];
    if (b[n - 1] < 0)
      cout << "NO\n";
    else {
      long long ad = 0, n2 = n * (n + 1) / 2;
      if (b[n - 1] % n2)
        cout << "NO\n";
      else {
        ad = b[n - 1] / n2;
        cout << "YES\n";
        for (long long x : a) cout << x + ad << " ";
        cout << "\n";
      }
    }
  }
  return 0;
}
