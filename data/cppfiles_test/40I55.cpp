#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
int n, m, q, turn;
int fa[maxn], cnt[maxn];
vector<int> g[maxn], ans[maxn];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void dfs(int u, int f, int b, vector<int>& p) {
  p.push_back(u);
  if (u == b) {
    ans[turn++] = p;
    return;
  }
  for (int v : g[u]) {
    if (f == v) continue;
    dfs(v, u, b, p);
  }
  p.pop_back();
}
void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) fa[i] = i;
  int u, v, fu, fv;
  for (int i = 1; i <= m; ++i) {
    cin >> u >> v;
    fu = find(u);
    fv = find(v);
    if (fu == fv) continue;
    g[u].push_back(v);
    g[v].push_back(u);
    fa[fu] = fv;
  }
  cin >> q;
  for (int i = 0; i < q; ++i) {
    cin >> u >> v;
    vector<int> p;
    dfs(u, u, v, p);
    for (int j : ans[i]) cnt[j] += 2, cout << j << " ";
    cnt[u]--;
    cnt[v]--;
    cout << endl;
  }
  int need = 0;
  for (int i = 1; i <= n; ++i)
    if (cnt[i] % 2) ++need;
  if (need) {
    cout << "NO" << endl;
    cout << (need + 1) / 2 << endl;
  } else {
    cout << "YES" << endl;
    for (int i = 0; i < q; ++i) {
      cout << ans[i].size() << endl;
      for (int j : ans[i]) cout << j << " ";
      cout << endl;
    }
  }
}
int main() {
  int T = 1;
  while (T--) solve();
}
