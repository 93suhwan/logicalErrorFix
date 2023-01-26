#include <bits/stdc++.h>
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const int INF = 1000000000 + 1e8;
const long long LINF = 2000000000000000000;
int n, m;
vector<int> parent;
vector<bool> used;
vector<vector<int>> g;
vector<set<int>> g2;
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
int res = 0;
set<int> leaves;
void dfs2(int v, int p = -1) {
  if (g2[v].empty()) {
    leaves.erase(v);
    res++;
    return;
  }
  auto to = *g2[v].begin();
  g2[v].erase(to);
  g2[to].erase(v);
  if (g2[v].size() == 0) leaves.erase(v);
  if (g2[v].size() == 1) {
    leaves.insert(v);
  }
  dfs2(to, v);
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
    if (ans.back()[0] != u) {
      reverse((ans[int(ans.size()) - 1]).begin(),
              (ans[int(ans.size()) - 1]).end());
    }
  }
  bool ok = true;
  for (auto to : mp)
    if (to.second % 2) ok = false;
  if (ok) {
    cout << "YES" << '\n';
    int i = 0;
    for (auto to : ans) {
      cout << to.size() << '\n';
      for (auto v : to) cout << v + 1 << ' ';
      cout << '\n';
    }
  } else {
    fill((used).begin(), (used).end(), false);
    for (auto to : mp) {
      if (to.second % 2) {
        g2[to.first.first].insert(to.first.second);
        g2[to.first.second].insert(to.first.first);
      }
    }
    for (int i = 0; i < n; i++)
      if (g2[i].size() == 1) leaves.insert(i);
    while (!leaves.empty()) {
      int v = *leaves.begin();
      dfs2(v);
    }
    cout << "NO" << '\n';
    cout << res;
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
