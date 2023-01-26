#include <bits/stdc++.h>
using namespace std;
long long bnpow(long long x, long long n) {
  if (n == 0) {
    return 1;
  }
  if (n & 1) {
    long long z = bnpow(x, n / 2);
    z = (z * z) % 1000000007;
    return (x * z) % 1000000007;
  } else {
    long long z = bnpow(x, n / 2);
    z = (z * z) % 1000000007;
    return z;
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    long long sum = 0;
    long long q = k;
    long long i = 0;
    while (q) {
      if (q & 1) {
        sum += bnpow(n, i);
        sum = sum % 1000000007;
      }
      i++;
      q = q >> 1;
    }
    cout << sum << '\n';
  }
}
