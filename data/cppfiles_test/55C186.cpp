#include <bits/stdc++.h>
using namespace std;
long long int T;
const long long int mod = 1e9 + 7;
const long long int maxn = 1e5 + 3;
void srinite() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  T = 1;
}
long long int bin_pow(long long int num, long long int power) {
  long long int ans = 1;
  while (power > 0) {
    if (power & 1) {
      ans = ((num % mod) * (ans % mod)) % mod;
      power--;
    } else {
      num = ((num % mod) * (num % mod)) % mod;
      power /= 2;
    }
  }
  return ans;
}
signed main() {
  srinite();
  for (long long int test = 1; test < T + 1; test++) {
    long long int k;
    cin >> k;
    long long int exponent = pow(2, k);
    exponent -= 2;
    if (exponent < 0) {
      cout << "issue" << endl;
      exponent += mod;
    }
    long long int ans = bin_pow(2, 2 * exponent);
    ans *= 6;
    ans %= mod;
    cout << ans << endl;
  }
  return 0;
}
