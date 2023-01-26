#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  vector<int> pf(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    pf[i] = (1ll * (a[i] - 1) * i) % mod;
    pf[i] = (pf[i] + pf[i - 1]) % mod;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int mn = a[i];
    int ret = 0;
    for (int j = i; j > 0; j--) {
      if (mn == 1) {
        ans = (ans + pf[j]) % mod;
        break;
      }
      int cnt = (a[j] + mn - 1) / mn;
      ret = (ret + cnt - 1) % mod;
      mn = a[j] / cnt;
      ans = (ans + ret) % mod;
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
