#include <bits/stdc++.h>
using namespace std;
vector<int> val;
vector<vector<int>> g;
vector<bool> vis;
int dfs(int u) {
  vis[u] = true;
  int mi = val[u];
  for (int v : g[u]) {
    if (!vis[v]) mi = min(mi, dfs(v));
  }
  return mi;
}
void solve() {
  int n, k;
  cin >> n >> k;
  map<int, vector<pair<int, int>>> byx, byy;
  val.resize(n);
  g.clear();
  g.resize(n);
  vis.assign(n, false);
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y >> val[i];
    byx[x].emplace_back(y, i);
    byy[y].emplace_back(x, i);
  }
  for (auto &p : byx) {
    sort((p.second).begin(), (p.second).end());
    for (int i = 1; i < ((int)(p.second).size()); ++i) {
      if (p.second[i].first - p.second[i - 1].first <= k) {
        int a = p.second[i].second, b = p.second[i - 1].second;
        g[a].push_back(b);
        g[b].push_back(a);
      }
    }
  }
  for (auto &p : byy) {
    sort((p.second).begin(), (p.second).end());
    for (int i = 1; i < ((int)(p.second).size()); ++i) {
      if (p.second[i].first - p.second[i - 1].first <= k) {
        int a = p.second[i].second, b = p.second[i - 1].second;
        g[a].push_back(b);
        g[b].push_back(a);
      }
    }
  }
  vector<int> comp;
  for (int i = 0; i < n; ++i) {
    if (!vis[i]) comp.push_back(dfs(i));
  }
  sort((comp).rbegin(), (comp).rend());
  int ans = 0;
  for (int i = 0; i < ((int)(comp).size()); ++i) {
    if (comp[i] < i) break;
    ans++;
  }
  ans--;
  cout << ans << "\n";
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) solve();
}
