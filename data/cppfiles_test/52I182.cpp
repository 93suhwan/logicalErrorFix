#include <bits/stdc++.h>
using namespace std;
long modularExponentiation(long x, long n, long mod) {
  long r = 1;
  while (n > 0) {
    if (n % 2 == 1) {
      r = ((r % mod) * (x % mod)) % mod;
    }
    x = ((x % mod) * (x % mod)) % mod;
    n = n / 2;
  }
  return (r % mod);
}
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    int n, k, i;
    cin >> n >> k;
    string s = "";
    while (k > 0) {
      if (k % 2 == 1)
        s = s + '1';
      else
        s = s + '0';
      k = k / 2;
    }
    long ans = 0;
    for (i = 0; i < s.size(); ++i) {
      if (s[i] == '1')
        ans = (ans % 1000000007 + modularExponentiation(n, i, 1000000007)) %
              1000000007;
    }
    cout << ans % 1000000007 << endl;
  }
  return 0;
}
