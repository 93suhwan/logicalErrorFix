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
    for (int j = last[i]; j >= 0;) {
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
      if (!j)
        break;
      else {
        int k = last[j] - 1;
        ret += (1ll * (j - k - 1) * (cnt - 1)) % mod;
        ret %= mod;
        int A = (1ll * (j - k - 1) * ((ret - cnt + 1 + mod) % mod)) % mod;
        int B = (1ll * (j - k - 2) * (j - k - 1) / 2) % mod;
        ans += (A + (1ll * B * (cnt - 1)) % mod) % mod;
        ans %= mod;
        j = k;
      }
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
