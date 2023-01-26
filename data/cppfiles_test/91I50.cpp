#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n), last(n), pf(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pf[i] = (1ll * (a[i] - 1) * (i + 1)) % mod;
    if (i) pf[i] = (pf[i] + pf[i - 1]) % mod;
  }
  for (int i = 1; i < n; i++) {
    last[i] = i;
    if (a[i] == a[i - 1]) {
      last[i] = last[i - 1];
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int mn = a[i];
    int ret = 0;
    for (int j = i; j >= 0; j--) {
      if (mn == 1) {
        ans += pf[j];
        ans %= mod;
        break;
      }
      int cnt = (a[j] + mn - 1) / mn;
      ret += cnt - 1;
      ret %= mod;
      mn = a[j] / cnt;
      ans += ret;
      ans %= mod;
    }
  }
  cout << ans << endl;
}
int main() {
  ios::sync_with_stdio(0);
  int tt;
  cin >> tt;
  while (tt--) solve();
}
