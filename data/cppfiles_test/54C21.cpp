#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, m;
int color[N];
vector<int> g[N];
int cnt[3];
bool dfs(int u) {
  cnt[color[u]] += (u <= n);
  for (auto v : g[u]) {
    if (color[v] == color[u]) return false;
    if (!color[v]) {
      color[v] = 3 - color[u];
      if (!dfs(v)) return false;
    }
  }
  return true;
}
void solve() {
  cin >> n >> m;
  int fake = n + 1;
  for (int i = 0; i <= n + m + 10; i++) {
    color[i] = 0;
    g[i].clear();
  }
  for (int i = 1; i <= m; i++) {
    int a, b;
    char type[20];
    cin >> a >> b >> type;
    if (*type == 'c') {
      g[a].push_back(fake);
      g[fake].push_back(a);
      g[b].push_back(fake);
      g[fake].push_back(b);
      fake++;
    } else {
      g[a].push_back(b);
      g[b].push_back(a);
    }
  }
  int ans = 0;
  bool ok = true;
  for (int i = 1; i <= n; i++)
    if (!color[i]) {
      cnt[1] = cnt[2] = 0;
      color[i] = 1;
      ok &= dfs(i);
      if (!ok) break;
      ans += max(cnt[1], cnt[2]);
    }
  cout << (ok ? ans : -1) << endl;
}
int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
