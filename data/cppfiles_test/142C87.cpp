#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;
const ll inf = 1LL << 60;
void solve() {
  int m, n;
  cin >> m >> n;
  vector<vector<ll>> a(m, vector<ll>(n));
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) cin >> a[i][j];
  if (n - 1 >= m) {
    ll ans = inf;
    for (int i = 0; i < n; i++) {
      ll tmp = 0;
      for (int j = 0; j < m; j++) tmp = max(tmp, a[j][i]);
      ans = min(ans, tmp);
    }
    cout << ans << '\n';
    return;
  }
  ll ok = 0, ng = inf;
  while (ng - ok > 1) {
    ll mid = (ok + ng) / 2;
    bool f = true;
    for (int i = 0; i < n; i++) {
      bool flag = false;
      for (int j = 0; j < m; j++)
        if (a[j][i] >= mid) flag = true;
      if (!flag) {
        f = false;
        break;
      }
    }
    if (!f) {
      ng = mid;
      continue;
    }
    f = false;
    for (int i = 0; i < m; i++) {
      int cnt = 0;
      for (int j = 0; j < n; j++)
        if (a[i][j] >= mid) cnt++;
      if (cnt >= 2) f = true;
    }
    if (f)
      ok = mid;
    else
      ng = mid;
  }
  cout << ok << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) solve();
}
