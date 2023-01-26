#include <bits/stdc++.h>
using namespace std;
const int M = 3e5 + 5;
vector<int> adj[M];
int l, timer, inTime[M], par[M], outTime[M], up[M][20];
void DFS(int cur, int p) {
  inTime[cur] = ++timer;
  up[cur][0] = par[cur] = p;
  for (int i = 1; i <= l; i++) up[cur][i] = up[up[cur][i - 1]][i - 1];
  for (int x : adj[cur]) {
    if (x ^ p) DFS(x, cur);
  }
  outTime[cur] = ++timer;
}
bool IsAncestor(int x, int y) {
  return inTime[x] <= inTime[y] && outTime[x] >= outTime[y];
}
int LCA(int x, int y) {
  if (IsAncestor(x, y)) return x;
  if (IsAncestor(y, x)) return y;
  for (int i = l; i >= 0; i--) {
    if (!IsAncestor(up[x][i], y)) x = up[x][i];
  }
  return up[x][0];
}
void PreProcess(int numberOfNodes) {
  l = ceil(log2(numberOfNodes));
  DFS(1, 1);
}
int FindPar(int n) {
  if (par[n] == n) return n;
  return par[n] = FindPar(par[n]);
}
int cnt[M];
vector<pair<int, int>> edges;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int i, lca, m, n, odd = 0, px, py, q, x, y;
  cin >> n >> m;
  for (i = 1; i <= n; i++) par[i] = i;
  while (m--) {
    cin >> x >> y;
    px = FindPar(x);
    py = FindPar(y);
    if (px != py) {
      par[py] = px;
      adj[x].emplace_back(y);
      adj[y].emplace_back(x);
    }
  }
  cin >> q;
  while (q--) {
    cin >> x >> y;
    ++cnt[x], ++cnt[y];
    edges.emplace_back(x, y);
  }
  for (i = 1; i <= n; i++) odd += (cnt[i] & 1);
  if (odd)
    cout << "NO\n" << odd / 2 << '\n';
  else {
    cout << "YES\n";
    PreProcess(n);
    for (auto [x, y] : edges) {
      lca = LCA(x, y);
      vector<int> v1, v2;
      while (x != lca) v1.emplace_back(x), x = par[x];
      while (y != lca) v2.emplace_back(y), y = par[y];
      v1.emplace_back(lca);
      while (!v2.empty()) v1.emplace_back(v2.back()), v2.pop_back();
      cout << (int)v1.size() << '\n';
      for (int it : v1) cout << it << ' ';
      cout << '\n';
    }
  }
  return 0;
}
