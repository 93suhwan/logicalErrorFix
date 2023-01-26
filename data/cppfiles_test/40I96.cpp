#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int inf = 1e9;
const double pi = acos(-1);
vector<int> eg[300005];
int idx[300005], vis[300005], a[300005], b[300005];
vector<int> ans[300005];
vector<int> tmp;
int dfsid = 0;
struct edge {
  int to, qid;
};
int fa[300005];
int ff(int x) { return fa[x] = (fa[x] == x ? x : ff(fa[x])); }
int merge(int u, int v) {
  int fu = ff(u), fv = ff(v);
  if (fu == fv)
    return 0;
  else {
    fa[fu] = fa[fv];
    return 1;
  }
}
vector<edge> qeg[300005];
int dfs_rt(int x, int to, int id, int qr) {
  vis[x] = id;
  if (x == to) {
    ans[qr].push_back(x);
    return 1;
  }
  for (int i : eg[x]) {
    if (vis[i] != id) {
      if (dfs_rt(i, to, id, qr)) {
        ans[qr].push_back(x);
        return 1;
      }
    }
  }
  return 0;
}
int dfs(int x, int to, int st, int qr) {
  idx[qr] = 1;
  if (to == st) {
    for (int i : tmp) {
      ans[qr].push_back(i);
    }
    tmp.clear();
    return 1;
  }
  dfs_rt(x, to, ++dfsid, qr);
  reverse(ans[qr].begin(), ans[qr].end());
  if (x == st) tmp.push_back(ans[qr][0]);
  for (int i = 1; i < ans[qr].size(); i++) {
    if (tmp.size() >= 2) {
      if (tmp[tmp.size() - 2] == ans[qr][i])
        tmp.pop_back();
      else
        tmp.push_back(ans[qr][i]);
    } else {
      tmp.push_back(ans[qr][i]);
    }
  }
  int nxt = 0;
  while (!qeg[to].empty() && idx[qeg[to].back().qid]) {
    qeg[to].pop_back();
  }
  if (!qeg[to].empty())
    nxt = qeg[to].back().to;
  else
    return 0;
  return dfs(to, nxt, st, qeg[to].back().qid);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    idx[i] = vis[i] = 0;
    fa[i] = i;
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    if (merge(u, v)) {
      eg[u].push_back(v);
      eg[v].push_back(u);
    }
  }
  int q;
  cin >> q;
  for (int o = 1; o <= q; o++) {
    cin >> a[o] >> b[o];
    qeg[a[o]].push_back({b[o], o});
    qeg[b[o]].push_back({a[o], o});
  }
  int fg = 0;
  for (int o = 1; o <= n; o++) {
    if (!idx[o]) {
      if (!dfs(a[o], b[o], a[o], o)) fg++;
    }
  }
  if (fg)
    cout << "NO\n" << fg << '\n';
  else {
    cout << "YES\n";
    for (int i = 1; i <= q; i++) {
      cout << ans[i].size() << '\n';
      if (ans[i][0] == b[i]) reverse(ans[i].begin(), ans[i].end());
      for (int j : ans[i]) cout << j << ' ';
      cout << '\n';
    }
  }
}
