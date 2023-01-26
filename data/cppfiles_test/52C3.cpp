#include <bits/stdc++.h>
const long long modulo = 1e9 + 7;
using namespace std;
long long binaryExponentiation(long long x, long long n, long long m) {
  if (n == 0) {
    return 1;
  }
  if (n % 2 == 0) {
    return binaryExponentiation(((x % m) * (x % m)) % m, n / 2, m);
  }
  return ((x % m) *
          binaryExponentiation(((x % m) * (x % m)) % m, (n - 1) / 2, m) % m) %
         m;
}
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long i = 0, j = 1;
    while (k / j > 0) {
      j *= 2;
      i++;
    }
    long long s[i];
    for (long long p = 0; p < i; p++) {
      if (((1LL << p) & k)) {
        s[p] = 1;
      } else {
        s[p] = 0;
      }
    }
    long long ans = 0;
    for (long long p = 0; p < i; p++) {
      if (s[p] == 1) {
        ans += binaryExponentiation(n, p, modulo);
        ans %= modulo;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
