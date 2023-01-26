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
    return ((n) * ((mu(tmp / 2) % mod) * (mu(tmp / 2) % mod)) % mod) % mod;
}
long long mu2(long long tmp) {
  if (tmp == 0) return 1;
  if (tmp == 1) return 2;
  if (tmp % 2 == 0)
    return ((mu2(tmp / 2) % mod) * (mu2(tmp / 2) % mod)) % mod;
  else
    return ((2 % mod) * ((mu2(tmp / 2) % mod) * (mu2(tmp / 2) % mod)) % mod) %
           mod;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    res = 0;
    int dem = 0;
    cin >> n >> k;
    while (k > 0) {
      dem = 0;
      long long tmp, kt = k;
      while (kt >= 2) {
        kt /= 2;
        dem++;
      }
      res = ((res % mod) + (mu(dem))) % mod;
      k -= mu2(dem);
    }
    cout << res << endl;
  }
}
