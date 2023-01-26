#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, q, a[N];
vector<int> adj[N];
namespace cd {
int sz[N];
int cpar[N];
bool vis[N];
void dfs(int n, int p = -1) {
  sz[n] = 1;
  for (int v : adj[n])
    if (v != p && !vis[v]) {
      dfs(v, n);
      sz[n] += sz[v];
    }
}
int centroid(int n) {
  dfs(n);
  int num = sz[n];
  int p = -1;
  do {
    int nxt = -1;
    for (int v : adj[n])
      if (v != p && !vis[v]) {
        if (2 * sz[v] > num) nxt = v;
      }
    p = n, n = nxt;
  } while (~n);
  return p;
}
void centroid_decomp(int n = 0, int p = -1) {
  int c = centroid(n);
  vis[c] = true;
  cpar[c] = p;
  for (int v : adj[c])
    if (!vis[v]) {
      centroid_decomp(v, c);
    }
}
}  // namespace cd
using cd::centroid_decomp;
using cd::cpar;
vector<vector<int> > treeJump(vector<int>& P) {
  int on = 1, d = 1;
  while (on < (int)(P).size()) on *= 2, d++;
  vector<vector<int> > jmp(d, P);
  for (int i = 1; i < (d); ++i)
    for (int j = 0; j < ((int)(P).size()); ++j)
      jmp[i][j] = jmp[i - 1][jmp[i - 1][j]];
  return jmp;
}
int jmp(vector<vector<int> >& tbl, int nod, int steps) {
  for (int i = 0; i < ((int)(tbl).size()); ++i)
    if (steps & (1 << i)) nod = tbl[i][nod];
  return nod;
}
int lca(vector<vector<int> >& tbl, vector<int>& depth, int a, int b) {
  if (depth[a] < depth[b]) swap(a, b);
  a = jmp(tbl, a, depth[a] - depth[b]);
  if (a == b) return a;
  for (int i = (int)(tbl).size(); i--;) {
    int c = tbl[i][a], d = tbl[i][b];
    if (c != d) a = c, b = d;
  }
  return tbl[0][a];
}
void dfs(int v, vector<int>& depth) {
  for (const int x : adj[v]) {
    depth[x] = depth[v] + 1;
    dfs(x, depth);
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  cin >> n >> q;
  for (int i = 0; i < (n); ++i) {
    cin >> a[i];
    a[i] = abs(a[i]);
  }
  for (int i = 0; i < (n - 1); ++i) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  centroid_decomp();
  int root = -1;
  for (int i = 0; i < (n); ++i) {
    if (cpar[i] == -1) {
      cpar[i] = i;
      root = i;
    }
    adj[i].clear();
  }
  for (int i = 0; i < (n); ++i) {
    if (cpar[i] != i) {
      adj[cpar[i]].push_back(i);
    }
  }
  vector<int> P(cpar, cpar + n), depth(n);
  vector<vector<int> > tbl = treeJump(P);
  dfs(root, depth);
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int u, c;
      cin >> u >> c;
      --u;
      a[u] = abs(c);
    } else {
      int u, v;
      cin >> u >> v;
      --u, --v;
      int anc = lca(tbl, depth, u, v);
      long long ans = 0;
      while (u != anc) {
        ans += a[u] + a[cpar[u]];
        u = cpar[u];
      }
      while (v != anc) {
        ans += a[v] + a[cpar[v]];
        v = cpar[v];
      }
      cout << ans << '\n';
    }
  }
}
