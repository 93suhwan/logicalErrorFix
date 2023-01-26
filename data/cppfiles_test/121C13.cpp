#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll minf = 0xc0c0c0c0c0c0c0c0;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(20);
  ll TC;
  cin >> TC;
  while (TC--) {
    ll n;
    string a, b;
    cin >> n >> a >> b;
    ll ga1 = 0, ga0 = 0, da1 = 0, da0 = 0;
    for (ll i = 0; i < n; i++) {
      if (a[i] == b[i]) {
        if (a[i] == '1') {
          ++ga1;
        } else {
          ++ga0;
        }
      } else {
        if (a[i] == '1') {
          ++da1;
        } else {
          ++da0;
        }
      }
    }
    ll res = inf;
    if ((ga0 + ga1) & 1) {
      if (ga1 == ga0 + 1) {
        res = min(res, ga0 + ga1);
      }
    }
    if ((da0 + da1) % 2 == 0) {
      if (da1 == da0) {
        res = min(res, da0 + da1);
      }
    }
    if (res == inf) {
      res = -1;
    }
    cout << res << '\n';
  }
  return 0;
}
