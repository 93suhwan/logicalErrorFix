#include <bits/stdc++.h>
using namespace std;
using llu = unsigned long long;
using ll = long long;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ll t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    ll prev = -1;
    ll ans = 1;
    for (ll i = 0; i < n; i++) {
      ll x;
      cin >> x;
      if (ans == -1) continue;
      if (x == 1) {
        ans += 1;
        if (prev == 1) ans += 4;
      }
      if (prev == 0 and x == 0) {
        ans = -1;
      }
      prev = x;
    }
    cout << ans << '\n';
  }
  return 0;
}
