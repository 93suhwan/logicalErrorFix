#include <bits/stdc++.h>
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const int INF = 1000000000 + 1e8;
const long long LINF = 2000000000000000000;
int n, m;
vector<int> parent;
vector<bool> used;
vector<vector<int>> g, g2;
map<pair<int, int>, int> mp;
pair<int, int> tie(int u, int v) { return {min(u, v), max(u, v)}; }
void dfs(int v, int p = -1) {
  used[v] = true;
  parent[v] = p;
  for (auto to : g[v]) {
    if (!used[to]) {
      dfs(to, v);
    }
  }
}
vector<vector<int>> ans;
void ansQuery(int u, int v) {
  vector<int> p1, p2;
  for (int i = v; i != -1; i = parent[i]) p1.push_back(i);
  for (int i = u; i != -1; i = parent[i]) p2.push_back(i);
  reverse((p1).begin(), (p1).end());
  reverse((p2).begin(), (p2).end());
  for (int i = 1; i < int(p1.size()); i++) {
    mp[tie(p1[i], p1[i - 1])]++;
  }
  for (int i = 1; i < int(p2.size()); i++) {
    mp[tie(p2[i], p2[i - 1])]++;
  }
  int i = 0;
  for (; i < min(int(p1.size()), int(p2.size())); i++) {
    if (p1[i] != p2[i]) break;
  }
  vector<int> res;
  for (int j = int(p1.size()) - 1; j >= i - 1; j--) res.push_back(p1[j]);
  for (int j = i; j < int(p2.size()); j++) res.push_back(p2[j]);
  ans.push_back(res);
}
vector<int> comp;
void dfs2(int v) {
  used[v] = true;
  comp.push_back(v);
  for (auto to : g2[v]) {
    if (!used[to]) {
      dfs2(to);
    }
  }
}
void solve() {
  cin >> n >> m;
  g.resize(n);
  parent.resize(n);
  used.resize(n);
  fill((used).begin(), (used).end(), false);
  g2.resize(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0);
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    ansQuery(u, v);
  }
  bool ok = true;
  for (auto to : mp)
    if (to.second % 2) ok = false;
  if (ok) {
    cout << "YES" << '\n';
    for (auto to : ans) {
      cout << to.size() << '\n';
      for (auto v : to) cout << v + 1 << ' ';
      cout << '\n';
    }
  } else {
    fill((used).begin(), (used).end(), false);
    for (auto to : mp) {
      if (to.second % 2) {
        g2[to.first.first].push_back(to.first.second);
        g2[to.first.second].push_back(to.first.first);
      }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (!used[i]) {
        comp.clear();
        dfs2(i);
        int cnt = 0;
        for (auto to : comp) {
          if (g2[to].size() == 1) {
            cnt++;
          }
        }
        ans += (cnt + 1) / 2;
      }
    }
    cout << "NO" << '\n';
    cout << ans;
  }
}
int main() {
  srand(time(0));
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tst = 1;
  while (tst--) {
    solve();
  }
}
