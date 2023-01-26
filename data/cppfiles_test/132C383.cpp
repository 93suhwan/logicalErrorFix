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
    long long v[7];
    long long i, j, f = 0;
    for (i = 0; i < 7; i++) cin >> v[i];
    cout << v[0] << " " << v[1] << " " << v[6] - v[0] - v[1] << "\n";
  }
  return 0;
}
