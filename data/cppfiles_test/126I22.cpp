#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e3 + 1;
int n, m, a[MAXN];
int u[MAXN], v[MAXN];
vector<int> ve[MAXN];
int fa[MAXN];
int root(int x) { return fa[x] = (fa[x] == x ? x : root(fa[x])); }
void merge(int u, int v) {
  fa[u] = v;
  for (auto it : ve[u]) ve[v].push_back(it);
  sort(ve[v].begin(), ve[v].end());
  ve[u].clear();
}
int query(int x) {
  x = root(x);
  return ve[x][(ve[x].size() + 1) / 2 - 1];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= m; ++i) {
    cin >> v[i] >> u[i];
  }
  for (int i = 1; i <= n; ++i) fa[i] = i, ve[i].push_back(a[i]);
  for (int T = 1; T <= n; ++T) {
    pair<int, pair<int, int> > bst;
    bst = make_pair(-INF, make_pair(-INF, -INF));
    for (int i = 1; i <= m; ++i) {
      if (query(u[i]) < query(v[i])) {
        bst = max(bst, make_pair(abs(query(u[i]) - query(v[i])),
                                 make_pair(root(u[i]), root(v[i]))));
      }
    }
    if (bst.first == -INF) break;
    merge(bst.second.first, bst.second.second);
  }
  for (int i = 1; i <= n; ++i) cout << query(i) << " ";
  cout << endl;
  return 0;
}
