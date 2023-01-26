#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long mu(long long a, long long b) {
  if (b == 0) return 1;
  if (b % 2 == 0)
    return ((mu(a, b / 2) % mod) * (mu(a, b / 2) % mod)) % mod;
  else
    return ((a % mod) * ((mu(a, b / 2) % mod) * (mu(a, b / 2) % mod)) % mod) %
           mod;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long n, k, res = 0;
    cin >> n >> k;
    while (k > 1) {
      long long tmp = (long long)log2(k);
      res = ((res % mod) + (mu(n, tmp) % mod)) % mod;
      k -= mu(2, tmp);
    }
    cout << res << endl;
  }
}
