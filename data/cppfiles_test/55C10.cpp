#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long qpow(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = ans * a % mod;
    a = a * a % mod;
    b >>= 1;
  }
  return ans;
}
signed main() {
  int k;
  cin >> k;
  cout << 6 * qpow(4, (1ll << k) - 2) % mod << '\n';
  return 0;
}
