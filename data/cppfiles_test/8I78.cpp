#include <bits/stdc++.h>
using namespace std;
vector<int> etour;
vector<int> adj[200005];
int preorder[200005];
int postorder[200005];
int timer = 0;
int dp[200005][20];
int a[200005];
void DFS(int u, int par) {
  preorder[u] = timer;
  etour.push_back(a[u]);
  timer++;
  dp[u][0] = par;
  for (int i = 1; i < 20; i++) {
    int z = dp[u][i - 1];
    if (z == -1) {
      dp[u][i] = -1;
      continue;
    }
    dp[u][i] = dp[z][i - 1];
  }
  for (auto x : adj[u]) {
    if (x == par) {
      continue;
    }
    DFS(x, u);
  }
  postorder[u] = timer;
  etour.push_back(-a[u]);
  timer++;
}
int is_ancestor(int u, int v) {
  if (preorder[u] <= preorder[v] && postorder[u] >= postorder[v]) {
    return 1;
  }
  return 0;
}
int lca(int u, int v) {
  if (is_ancestor(u, v)) {
    return u;
  }
  int z = u;
  for (int i = 19; i >= 0; i--) {
    if (dp[z][i] == -1) {
      continue;
    }
    if (is_ancestor(dp[z][i], v)) {
      continue;
    }
    z = dp[z][i];
  }
  return dp[z][0];
}
struct segtree {
  vector<int> v;
  void init(int n) {
    int curr = 1;
    while (curr < n) {
      curr *= 2;
    }
    for (int i = 0; i < 2 * curr; i++) {
      v.push_back(0);
    }
  }
  void update(int lx, int rx, int i, int z, int curr) {
    if (rx - lx == 1) {
      v[curr] = z;
      return;
    }
    int m = (lx + rx) / 2;
    if (i < m) {
      update(lx, m, i, z, 2 * curr + 1);
    } else {
      update(m, rx, i, z, 2 * curr + 2);
    }
    v[curr] = v[2 * curr + 1] + v[2 * curr + 2];
  }
  int getsum(int lx, int rx, int l, int r, int curr) {
    if (lx >= l && rx <= r) {
      return v[curr];
    }
    if (lx >= r || rx <= l) {
      return 0;
    }
    int m = (lx + rx) / 2;
    return getsum(lx, m, l, r, 2 * curr + 1) +
           getsum(m, rx, l, r, 2 * curr + 2);
  }
};
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] = abs(a[i]);
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  DFS(0, -1);
  struct segtree st;
  int z = etour.size();
  st.init(z);
  for (int i = 0; i < z; i++) {
    st.update(0, z, i, etour[i], 0);
  }
  while (q--) {
    int qtype, u, v;
    cin >> qtype >> u >> v;
    if (qtype == 1) {
      v = abs(v);
      u--;
      a[u] = v;
      st.update(0, z, preorder[u], v, 0);
      st.update(0, z, postorder[u], -v, 0);
    } else {
      u--;
      v--;
      int zz = lca(u, v);
      int pok = st.getsum(0, z, preorder[zz], preorder[u] + 1, 0);
      int yo = st.getsum(0, z, preorder[zz], preorder[v] + 1, 0);
      pok += yo;
      pok -= a[zz];
      pok = pok * 2;
      pok -= a[u];
      pok -= a[v];
      cout << pok << "\n";
    }
  }
}
