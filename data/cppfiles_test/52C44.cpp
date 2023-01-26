#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long n, k, res = 0;
long long mu(long long a, long long b) {
  long long tmp;
  if (b == 0) return 1;
  tmp = mu(a, b / 2) % mod;
  if (b % 2 == 0) return ((tmp % mod) * (tmp % mod)) % mod;
  return ((((a % mod) * (tmp % mod)) % mod) * (tmp % mod)) % mod;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    res = 0;
    cin >> n >> k;
    while (k > 0) {
      long long dem = log2(k);
      res = ((res % mod) + (mu(n, dem) % mod)) % mod;
      k -= mu(2, dem);
    }
    cout << res << endl;
  }
}
