#include <bits/stdc++.h>
using namespace std;
void dbg() { cout << "DEBUG\n"; }
const int INF = 1e9;
const long long LINF = 1e18;
const long long mod = 998244353;
const int maxn = 2e5 + 100;
long long fac[maxn];
long long inv(int x) {
  long long second = 1;
  for (; x > 1; x = mod % x) second = second * (mod - mod / x) % mod;
  return second;
}
void pre() {
  fac[0] = 1;
  for (int i = 1; i <= 200010; i++) fac[i] = (fac[i - 1] * i) % mod;
  return;
}
long long C(int n, int m) {
  if (m > n) return 0;
  if (m == 0) return 1;
  return (fac[n] * inv(fac[m])) % mod * inv(fac[n - m]) % mod;
}
void solve() {
  long long n;
  cin >> n;
  vector<int> arr(n + 1);
  for (int i = 1; i <= n; i++) cin >> arr[i];
  int mx = -1, sc_mx = -1;
  for (int i = 1; i <= n; i++) {
    if (arr[i] > mx) {
      sc_mx = mx;
      mx = arr[i];
    } else if (arr[i] > sc_mx)
      sc_mx = arr[i];
  }
  if (mx - sc_mx > 1) {
    cout << "0" << '\n';
    return;
  }
  int cnt_mx = 0, cnt_se_mx = 0;
  for (int i = 1; i <= n; i++) {
    if (arr[i] == mx)
      cnt_mx++;
    else if (arr[i] == sc_mx)
      cnt_se_mx++;
  }
  long long tmp = (((1 + n - 1) * (n - 1) % mod) * inv(2) % mod);
  if (cnt_mx > 1) {
    long long ans = fac[n];
    cout << ans << '\n';
  } else if (cnt_se_mx > 1) {
    long long ans = fac[n];
    for (int i = n - 1; i >= cnt_se_mx; i--) {
      ans -= (C(n - cnt_se_mx - 1, i - cnt_se_mx) * fac[i] % mod) *
             fac[n - i - 1] % mod;
      if (ans < 0) ans += mod;
    }
    cout << ans << '\n';
  } else {
    long long ans = (tmp * fac[n - 2]) % mod;
    cout << ans << '\n';
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  pre();
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) solve();
  return 0;
}
