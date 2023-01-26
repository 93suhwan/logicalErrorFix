#include <bits/stdc++.h>
using namespace std;
long long fac[63];
long long qpow(long long a, long long b, long long mod) {
  long long ans = 1;
  while (b > 0) {
    if (b & 1) ans = (ans * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return ans;
}
long long inv(long long a) { return qpow(a, 1000000007 - 2, 1000000007); }
void init() {
  fac[0] = 1;
  for (int i = 1; i <= 61; ++i) {
    fac[i] = fac[i - 1] * i;
  }
}
long long C(long long n, long long m) {
  return fac[n] * inv(fac[m] * fac[n - m] % 1000000007) % 1000000007;
}
void solve() {
  long long n;
  cin >> n;
  long long ans = pow(2, n) - 1;
  ans = qpow(4, ans - 1, 1000000007) * 6 % 1000000007;
  cout << ans << endl;
}
int main() {
  std::ios::sync_with_stdio(false);
  int t;
  solve();
  return 0;
}
