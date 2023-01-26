#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> deg(n + 1, {0, 0});
  int cnt = n;
  while (m--) {
    int a, b;
    cin >> a >> b;
    if (b < a) swap(a, b);
    deg[a].second++;
    deg[b].first++;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (deg[i].second == 0) ans++;
  int q;
  cin >> q;
  while (q--) {
    int tt;
    cin >> tt;
    if (tt == 3) {
      cout << ans << "\n";
      continue;
    }
    int a, b;
    cin >> a >> b;
    if (b < a) swap(a, b);
    if (tt == 2) {
      if (deg[a].second == 1) ans++;
      deg[a].second--;
      deg[b].first--;
    } else {
      if (deg[a].second == 0) ans--;
      deg[a].second++;
      deg[b].first++;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    solve();
    cout << "\n";
  }
}
