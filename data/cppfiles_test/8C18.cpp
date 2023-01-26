#include <bits/stdc++.h>
using namespace std;
vector<long long> etour;
vector<long long> adj[200005];
long long preorder[200005];
long long postorder[200005];
long long timer = 0;
long long dp[200005][20];
long long a[200005];
void DFS(long long u, long long par) {
  preorder[u] = timer;
  etour.push_back(a[u]);
  timer++;
  dp[u][0] = par;
  for (long long i = 1; i < 20; i++) {
    long long z = dp[u][i - 1];
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
long long is_ancestor(long long u, long long v) {
  if (preorder[u] <= preorder[v] && postorder[u] >= postorder[v]) {
    return 1;
  }
  return 0;
}
long long lca(long long u, long long v) {
  if (is_ancestor(u, v)) {
    return u;
  }
  long long z = u;
  for (long long i = 19; i >= 0; i--) {
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
  vector<long long> v;
  void init(long long n) {
    long long curr = 1;
    while (curr < n) {
      curr *= 2;
    }
    for (long long i = 0; i < 2 * curr; i++) {
      v.push_back(0);
    }
  }
  void update(long long lx, long long rx, long long i, long long z,
              long long curr) {
    if (rx - lx == 1) {
      v[curr] = z;
      return;
    }
    long long m = (lx + rx) / 2;
    if (i < m) {
      update(lx, m, i, z, 2 * curr + 1);
    } else {
      update(m, rx, i, z, 2 * curr + 2);
    }
    v[curr] = v[2 * curr + 1] + v[2 * curr + 2];
  }
  long long getsum(long long lx, long long rx, long long l, long long r,
                   long long curr) {
    if (lx >= l && rx <= r) {
      return v[curr];
    }
    if (lx >= r || rx <= l) {
      return 0;
    }
    long long m = (lx + rx) / 2;
    return getsum(lx, m, l, r, 2 * curr + 1) +
           getsum(m, rx, l, r, 2 * curr + 2);
  }
};
long long bforce(long long u, long long v) {
  queue<long long> q;
  q.push(u);
  long long dist[100005];
  long long visited[100005];
  memset(visited, 0, sizeof(visited));
  visited[u] = 1;
  dist[u] = a[u];
  while (!q.empty()) {
    long long z = q.front();
    for (auto x : adj[z]) {
      if (visited[x]) {
        continue;
      }
      dist[x] = dist[z] + a[x];
      q.push(x);
      visited[x] = 1;
    }
    q.pop();
  }
  return 2 * dist[v] - (a[u] + a[v]);
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, q;
  cin >> n >> q;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    a[i] = abs(a[i]);
  }
  for (long long i = 0; i < n - 1; i++) {
    long long u, v;
    cin >> u >> v;
    u--;
    v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  DFS(0, -1);
  struct segtree st;
  long long z = etour.size();
  assert(z == (2 * n));
  st.init(z);
  for (long long i = 0; i < z; i++) {
    st.update(0, z, i, etour[i], 0);
  }
  while (q--) {
    long long qtype, u, v;
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
      long long zz = lca(u, v);
      long long pok = st.getsum(0, z, preorder[zz], preorder[u] + 1, 0);
      long long yo = st.getsum(0, z, preorder[zz], preorder[v] + 1, 0);
      pok += yo;
      pok -= a[zz];
      pok = pok * 2;
      pok -= a[u];
      pok -= a[v];
      cout << pok << "\n";
    }
  }
}
