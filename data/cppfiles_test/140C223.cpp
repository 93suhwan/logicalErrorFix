#include <bits/stdc++.h>
using namespace std;
const long long int mod = 1000000007;
const long long int N = 1e9 + 2;
long long int gcd(long long int a, long long int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long int bin_exp(long long int a, long long int b) {
  long long int res = 1;
  if (b == 0) return 1;
  while (b) {
    if (b % 2 == 0) {
      a = (a % mod) * (a % mod);
      b /= 2;
    } else {
      res = (res % mod) * (a % mod);
      b--;
    }
  }
  return res;
}
long long int mod_inv(long long int a, long long int b) {
  return bin_exp(a, b - 2) % b;
}
long long int fact[100];
void cal() {
  fact[0] = 1;
  for (long long int i = 1; i < N; i++) {
    fact[i] = (fact[i - 1] % mod * i % mod) % mod;
  }
}
void solve() {
  long long int n;
  cin >> n;
  long long int x = int32_t(sqrt(n)) + int32_t(cbrt(n));
  cout << x - int32_t(sqrt(cbrt(n))) << endl;
}
int32_t main() {
  long long int t = 1;
  cin >> t;
  while (t--) solve();
  return 0;
}
