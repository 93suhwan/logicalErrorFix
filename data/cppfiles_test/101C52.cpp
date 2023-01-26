#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 1;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> x(n), y(m);
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < m; i++) cin >> y[i];
    unordered_map<int, int> count_x, count_y;
    map<pair<int, int>, int> count_xx, count_yy;
    while (k--) {
      int u, v;
      cin >> u >> v;
      auto px = lower_bound(x.begin(), x.end(), u);
      auto py = lower_bound(y.begin(), y.end(), v);
      if (*px == u && *py == v) continue;
      if (*px == u) {
        count_y[*py - y[0]] += 1;
        count_yy[{*py - y[0], u}] += 1;
      } else {
        count_x[*px - x[0]] += 1;
        count_xx[{*px - x[0], v}] += 1;
      }
    }
    long long ans = 0;
    for (auto &i : count_x) ans += i.second * (i.second - 1ll) / 2;
    for (auto &i : count_y) ans += i.second * (i.second - 1ll) / 2;
    for (auto &i : count_xx) ans -= i.second * (i.second - 1ll) / 2;
    for (auto &i : count_yy) ans -= i.second * (i.second - 1ll) / 2;
    cout << ans << "\n";
  }
  return 0;
}
