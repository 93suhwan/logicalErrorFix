#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
long long pow_mod(long long a, long long b) {
  long long res = 1L;
  a = a % MOD;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % MOD;
    }
    b /= 2;
    a = (a * a) % MOD;
  }
  return res;
}
int main() {
  int t, n, k;
  long long ans, a, b, num, inverse, common_power;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    if (n & 1) {
      ans = pow_mod(2, n - 1);
      ans = (ans + 1) % MOD;
      ans = pow_mod(ans, k);
    } else {
      common_power = pow_mod(2, n - 1);
      a = pow_mod(common_power * 2, k);
      b = pow_mod(common_power - 1, k);
      num = (a - b);
      if (num < 0) num += MOD;
      inverse = pow_mod(common_power + 1, 1000000005);
      ans = (inverse * num) % MOD;
      ans = (ans + b) % MOD;
    }
    cout << ans << "\n";
  }
  return 0;
}
