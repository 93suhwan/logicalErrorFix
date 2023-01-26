#include <bits/stdc++.h>
using namespace std;
long long int power(long long int x, long long int y);
long long int gcd(long long int a, long long int b);
vector<long long int> ft = {1};
long long int modInv(long long int i) { return power(i, 1000000007 - 2); }
long long int ncr(long long int n, long long int r) {
  return (n >= r ? (ft[n] * modInv(ft[r])) % 1000000007 * modInv(ft[n - r]) %
                       1000000007
                 : 0);
}
long long int power(long long int x, long long int y) {
  long long int res = 1;
  x %= 1000000007;
  while (y > 0) {
    if (y & 1) res = (res * x) % 1000000007;
    y = y >> 1;
    x = (x * x) % 1000000007;
  }
  return res % 1000000007;
}
long long int gcd(long long int a, long long int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int xx[300005];
  xx[0] = 0;
  for (long long int i = 1; i < 300005; i++) {
    xx[i] = xx[i - 1] ^ i;
  }
  long long int t;
  cin >> t;
  while (t--) {
    long long int a, b;
    cin >> a >> b;
    long long int x = xx[a - 1];
    long long int req = b ^ x;
    if (req == 0) {
      cout << a << "\n";
    } else if (req == a) {
      cout << a + 2 << "\n";
    } else {
      cout << a + 1 << "\n";
    }
  }
}
