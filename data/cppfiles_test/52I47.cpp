#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long n, k, res = 0;
long long mu(long long tmp) {
  if (tmp == 0) return 1;
  if (tmp == 1) return n;
  if (tmp % 2 == 0)
    return ((mu(tmp / 2) % mod) * (mu(tmp / 2) % mod)) % mod;
  else
    return ((n % mod) * ((mu(tmp / 2) % mod) * (mu(tmp / 2) % mod)) % mod) %
           mod;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    res = 0;
    cin >> n >> k;
    while (k > 0) {
      long long tmp = (long long)log2(k);
      res = ((res % mod) + (mu(tmp) % mod)) % mod;
      k -= pow(2, tmp);
    }
    cout << res << endl;
  }
}
