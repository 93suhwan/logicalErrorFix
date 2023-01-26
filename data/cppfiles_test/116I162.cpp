#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;
void solve() {
  int n, x;
  cin >> n;
  vector<ll> dp1(n + 5, 0), dp2(n + 5, 0), dp3(n + 5, 0);
  for (int i = 0; i < n; i++) {
    cin >> x;
    if (x == 0)
      ((dp1[0] *= 2) += 1) %= MOD;
    else
      ((dp1[x] *= 2) += dp1[x - 1]) %= MOD;
    if (x == 1)
      ((dp2[x] *= 2) += 1) %= MOD;
    else
      ((dp2[x] *= 2) += dp1[x - 2]) %= MOD;
    if (x > 2) ((dp3[x] *= 2) += dp3[x - 2]) %= MOD;
    ((dp3[x] *= 2) += dp2[x + 2]) %= MOD;
  }
  ll ans = 0;
  for (int i = 0; i < n + 5; i++) {
    (ans += dp1[i]) %= MOD;
    (ans += dp2[i]) %= MOD;
    (ans += dp3[i]) %= MOD;
  }
  cout << ans << '\n';
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
}
