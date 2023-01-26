#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
int from[300001][19], n, m, q, deg[300001], depth[300001];
bool visited[300001];
vector<int> G[300001];
P qry[300001];
void dfs(int now) {
  visited[now] = true;
  for (int x : G[now]) {
    if (visited[x]) continue;
    from[x][0] = now;
    depth[x] = depth[now] + 1;
    dfs(x);
  }
}
int lca(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  for (int i = 18; i >= 0; i--) {
    if (depth[from[u][i]] >= depth[v]) u = from[u][i];
  }
  if (u == v) return u;
  for (int i = 18; i >= 0; i--) {
    if (from[u][i] != from[v][i]) {
      u = from[u][i];
      v = from[v][i];
    }
  }
  return from[u][0];
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  int u, v;
  while (m--) {
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> qry[i].first >> qry[i].second;
    deg[qry[i].first]++;
    deg[qry[i].second]++;
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (deg[i] % 2 == 1) cnt++;
  }
  if (cnt) {
    cout << "NO\n" << cnt / 2 << '\n';
  } else {
    cout << "YES\n";
    from[1][0] = 1;
    depth[1] = 1;
    dfs(1);
    for (int i = 1; i < 19; i++) {
      for (int j = 1; j <= n; j++) from[j][i] = from[from[j][i - 1]][i - 1];
    }
    for (int i = 0; i < q; i++) {
      int qq = lca(qry[i].first, qry[i].second), u = qry[i].first,
          v = qry[i].second;
      vector<int> ans1, ans2;
      while (u != qq) {
        ans1.push_back(u);
        u = from[u][0];
      }
      ans1.push_back(qq);
      while (v != qq) {
        ans2.push_back(v);
        v = from[v][0];
      }
      reverse(ans2.begin(), ans2.end());
      cout << ans1.size() + ans2.size() << '\n';
      for (int x : ans1) cout << x << ' ';
      for (int x : ans2) cout << x << ' ';
      cout << '\n';
    }
  }
}
