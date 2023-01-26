#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> g;
vector<int> ans, col, cnt, o, pos;
struct req {
  int l, k, i;
};
vector<vector<req>> q;
void dfs(int v, int p) {
  int l = pos[col[v]], r = o.size();
  while (l != r - 1) {
    int mid = (l + r) / 2;
    if (cnt[o[mid]] <= cnt[col[v]])
      l = mid;
    else
      r = mid;
  }
  int st = pos[col[v]];
  pos[o[l]] = pos[col[v]];
  swap(o[pos[col[v]]], o[l]);
  pos[col[v]] = l;
  cnt[col[v]]++;
  for (auto it : q[v]) {
    int le = 0, ri = o.size();
    while (le != ri - 1) {
      int mid = (le + ri) / 2;
      if (cnt[mid] < it.l)
        le = mid;
      else
        ri = mid;
    }
    ans[it.i] = o[le + it.k];
  }
  for (auto u : g[v]) {
    if (u == p) continue;
    dfs(u, v);
  }
  pos[col[v]] = st;
  swap(o[pos[col[v]]], o[l]);
  pos[o[l]] = l;
  cnt[col[v]]--;
}
void solve() {
  int n, qu;
  cin >> n >> qu;
  g.assign(n, {}), q.assign(n, {}), ans.assign(qu, 0), col.assign(n, 0),
      cnt.assign(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> col[i];
    col[i]--;
  }
  for (int i = 0; i < n - 1; ++i) {
    int p;
    cin >> p;
    g[p - 1].push_back(i);
  }
  for (int i = 0; i < n; ++i) {
    o.push_back(i), pos.push_back(i);
  }
  for (int i = 0; i < qu; ++i) {
    int v, l, k;
    cin >> v >> l >> k;
    k--, v--;
    q[v].push_back({l, k});
  }
  dfs(0, -1);
  for (int i = 0; i < qu; ++i) {
    cout << ans[i] << " ";
  }
  cout << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
