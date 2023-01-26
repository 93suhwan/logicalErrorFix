#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 200005;
const int MOD = 1e9 + 7;
set<int> g[MAXN];
int tp[MAXN];
inline void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) tp[i] = 1;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    if (u > v) swap(u, v);
    tp[u] = 0;
    g[u].insert(v);
    g[v].insert(u);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += tp[i];
  }
  int q;
  cin >> q;
  while (q--) {
    int opt;
    cin >> opt;
    if (opt == 1) {
      int u, v;
      cin >> u >> v;
      if (u > v) swap(u, v);
      if (tp[u] == 1) {
        tp[u] = 0;
        ans--;
      }
      g[u].insert(v);
      g[v].insert(u);
    } else if (opt == 2) {
      int u, v;
      cin >> u >> v;
      if (u > v) swap(u, v);
      g[u].erase(v);
      g[v].erase(u);
      auto it = g[u].upper_bound(u);
      if (it == g[u].end() && tp[u] == 0) {
        tp[u] = 1;
        ans++;
      }
      auto that = g[v].upper_bound(v);
      if (that == g[v].end() && tp[v] == 0) {
        tp[v] = 1;
        ans++;
      }
    } else {
      cout << ans << "\n";
    }
  }
  return;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
