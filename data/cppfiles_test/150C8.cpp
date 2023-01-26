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
    vector<long long> v(n);
    long long i, m = 0, cnt[3] = {};
    for (i = 0; i < n; i++) {
      cin >> v[i];
      m = max(m, v[i]);
      cnt[v[i] % 3] = 1;
    }
    long long f = 0, g = 0;
    for (i = 0; i < n; i++) {
      if (v[i] == 1) f = 1;
      if (v[i] == m - 1) g = 1;
    }
    if (m % 3 == 0)
      cout << m / 3 + (cnt[1] | cnt[2]) << "\n";
    else if (m % 3 == 1) {
      if (!cnt[2] || (cnt[2] && !f && !g))
        cout << m / 3 + 1 << "\n";
      else
        cout << m / 3 + 2 << "\n";
    } else
      cout << m / 3 + 1 + cnt[1] << "\n";
  }
  return 0;
}
