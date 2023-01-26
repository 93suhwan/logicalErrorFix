#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long mod_pow(long long b, long long p) {
  long long ans = 1;
  while (p) {
    if (p & 1) {
      ans = (1ll * ans * b) % mod;
      p--;
    }
    b = (1ll * b * b) % mod;
    p /= 2;
  }
  return ans;
}
const long long N = (2e5 + 5);
long long fac[N], inv_fac[N];
void calc_fac() {
  fac[0] = 1;
  inv_fac[0] = 1;
  for (long long i = 1; i < N; i++) {
    fac[i] = (1ll * fac[i - 1] * i) % mod;
    inv_fac[i] = mod_pow(fac[i], mod - 2);
  }
}
void solve() {
  long long n, k;
  cin >> n >> k;
  if (k == 0) {
    cout << 1;
    cout << '\n';
    return;
  }
  long long s = 0;
  for (long long i = 0; i < n; i++) {
    if (i & 1) continue;
    long long c = 1ll * fac[n] * mod_pow(fac[n - i], mod - 2) % mod *
                  mod_pow(fac[i], mod - 2) % mod;
    s = (s + c) % mod;
  }
  long long p = mod_pow(2, n);
  long long right = mod_pow(p, k);
  long long left = 1;
  long long ans = 0;
  for (long long i = 0; i < k; i++) {
    right = right * mod_pow(p, mod - 2) % mod;
    ans = (ans + 1ll * left * right) % mod;
    left = left * s % mod;
  }
  ans += mod_pow(s, k);
  cout << ans;
  cout << '\n';
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  calc_fac();
  long long tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}
