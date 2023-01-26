#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 7;
const int MOD = 1e9 + 7;
vector<int> Gimp[MAXN];
vector<int> Gcrew[MAXN];
vector<int> G[MAXN];
int comp[MAXN];
int compSize[MAXN];
bool vis[MAXN];
bool col[MAXN];
bool ans;
int res;
int allSize;
void DFScomp(int v, int nr) {
  comp[v] = nr;
  ++compSize[nr];
  for (auto u : Gcrew[v]) {
    if (comp[u] > 0) continue;
    DFScomp(u, nr);
  }
}
void DFScolor(int v, bool c) {
  vis[v] = true;
  col[v] = c;
  if (c) res += compSize[v];
  allSize += compSize[v];
  for (auto u : G[v]) {
    if (vis[u]) {
      if (col[u] == c) ans = false;
      continue;
    }
    DFScolor(u, !c);
  }
}
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    int u, v;
    string c;
    cin >> u >> v >> c;
    if (c == "imposter") {
      Gimp[v].push_back(u);
      Gimp[u].push_back(v);
    } else {
      Gcrew[v].push_back(u);
      Gcrew[u].push_back(v);
    }
  }
  int c = 1;
  for (int i = 1; i <= n; ++i) {
    if (comp[i] == 0) {
      DFScomp(i, c);
      ++c;
    }
  }
  for (int v = 1; v <= n; ++v) {
    for (auto u : Gimp[v]) {
      G[comp[u]].push_back(comp[v]);
      G[comp[v]].push_back(comp[u]);
    }
  }
  int best = 0;
  ans = true;
  for (int i = 1; i < c; ++i) {
    if (!vis[i]) {
      res = 0;
      allSize = 0;
      DFScolor(i, 0);
      best += max(res, allSize - res);
    }
  }
  if (!ans) best = -1;
  cout << best << '\n';
  for (int i = 1; i <= n; ++i) {
    Gimp[i].clear();
    Gcrew[i].clear();
    G[i].clear();
    col[i] = 0;
    comp[i] = 0;
    compSize[i] = 0;
    vis[i] = false;
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int T;
  cin >> T;
  while (T--) solve();
  return 0;
}
