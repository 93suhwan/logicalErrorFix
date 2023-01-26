#include <bits/stdc++.h>
using namespace std;
const long long N = 1e6 + 9;
const long long inf = 0x3f3f3f3f;
const long long mod = 998244353;
long long a[N];
long long fac[N], inv_fac[N];
long long q_pow(long long a, long long b, long long mod) {
  long long ret = 1;
  for (long long x = a; b; b >>= 1, (x *= x) %= mod)
    if (b & 1) (ret *= x) %= mod;
  return ret;
}
long long inv(long long x) { return q_pow(x, mod - 2, mod); }
void init() {
  fac[0] = inv_fac[0] = 1;
  for (int i = 1; i < N; i++) {
    fac[i] = (fac[i - 1] * 1ll * i) % mod;
    inv_fac[i] = inv(fac[i]);
  }
}
long long C(long long n, long long m) {
  return fac[n] * inv_fac[m] % mod * inv_fac[n - m] % mod;
}
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + 1 + n, greater<int>());
  long long ma1 = 1, ma2 = 0;
  for (int i = 2; i <= n; i++) {
    if (a[i] == a[1])
      ma1++;
    else if (a[i] + 1 == a[1])
      ma2++;
    else {
      if (ma2 == 0) {
        cout << 0 << endl;
        return;
      }
      break;
    }
  }
  if (ma1 > 1) {
    cout << fac[n] << endl;
  } else {
    cout << fac[n] * inv_fac[ma2 + 1] % mod * ma2 % mod * fac[ma2] % mod
         << endl;
  }
}
signed main() {
  init();
  long long t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
