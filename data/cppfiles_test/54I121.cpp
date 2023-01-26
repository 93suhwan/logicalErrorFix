#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int mod_pow(int b, int p) {
  int ans = 1;
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
const int N = (2e5 + 5);
int fac[N], inv_fac[N];
void calc_fac() {
  fac[0] = 1;
  inv_fac[0] = 1;
  for (int i = 1; i < N; i++) {
    fac[i] = (fac[i - 1] * i) % mod;
    inv_fac[i] = mod_pow(fac[i], mod - 2);
  }
}
void solve() {
  int n, k;
  cin >> n >> k;
  int t1 = 0;
  for (int i = 0; i < n; i += 2) {
    t1 = (t1 + 1ll * fac[n] * inv_fac[n - i] % mod * inv_fac[i] % mod) % mod;
  }
  if (n & 1) t1 = (t1 * 1ll + 1) % mod;
  if (n & 1) {
    int ans = 0;
    ans = (1ll * ans + mod_pow(t1, k));
    cout << ans;
    cout << '\n';
    return;
  }
  int t2 = mod_pow(2, n);
  int r = mod_pow(t2, k);
  int ans = 0;
  int l = 1;
  for (int i = 0; i < k; i++) {
    r = 1ll * r * mod_pow(t2, mod - 2) % mod;
    ans = (ans + 1ll * l * r) % mod;
    l = 1ll * l * t1 % mod;
  }
  ans = (1ll * ans + l) % mod;
  cout << ans;
  cout << '\n';
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  calc_fac();
  int tc;
  cin >> tc;
  while (tc--) solve();
  return 0;
}
