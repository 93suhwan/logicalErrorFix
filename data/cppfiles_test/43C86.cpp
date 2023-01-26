#include <bits/stdc++.h>
using namespace std;
const int MX = 6e5 + 10;
int U[MX];
int V[MX];
int W[MX];
bool ans[MX];
int rnk[MX];
int parent[MX];
int findSet(int i) {
  if (parent[i] == i) return i;
  parent[i] = findSet(parent[i]);
  return parent[i];
}
void unionSet(int i, int j) {
  int x = findSet(i);
  int y = findSet(j);
  if (y != x) {
    if (rnk[x] <= rnk[y]) swap(x, y);
    parent[y] = x;
    if (rnk[x] == rnk[y]) rnk[y]++;
  }
  return;
}
vector<int> eulerPath;
vector<int> adj[MX];
vector<int> pes[MX];
int anc[MX][20];
int pos[2][MX];
int T[MX];
int L[MX];
int XOR[MX];
void build(int n) {
  for (int i = 0; i <= n; i++) {
    for (int j = 0; (1ll << j) <= n; j++) {
      anc[i][j] = -1;
    }
  }
  for (int i = 0; i <= n; i++) anc[i][0] = T[i];
  for (int j = 1; (1ll << j) <= n; j++) {
    for (int i = 0; i <= n; i++) {
      if (anc[i][j - 1] != -1) anc[i][j] = anc[anc[i][j - 1]][j - 1];
    }
  }
  return;
}
int lca(int u, int v) {
  if (L[u] < L[v]) swap(u, v);
  int lg = 63 - (__builtin_clzll(L[u]));
  for (int i = lg; i >= 0; i--) {
    if (L[u] - (1ll << i) >= L[v]) u = anc[u][i];
  }
  if (u == v) return u;
  for (int i = lg; i >= 0; i--) {
    if (anc[u][i] != -1 && anc[u][i] != anc[v][i]) {
      u = anc[u][i];
      v = anc[v][i];
    }
  }
  return T[u];
}
void dfs(int u, int ac = 0) {
  XOR[u] = ac;
  pos[0][u] = eulerPath.size();
  eulerPath.push_back(u);
  int sz = adj[u].size();
  for (int i = 0; i < sz; i++) {
    int v = adj[u][i];
    int w = pes[u][i];
    if (L[v] == -1) {
      T[v] = u;
      L[v] = L[u] + 1;
      dfs(v, ac ^ w);
    }
  }
  pos[1][u] = eulerPath.size();
  eulerPath.push_back(u);
  return;
}
struct FenwickTree {
  int tree[MX];
  FenwickTree() {
    for (int i = 0; i < MX; i++) tree[i] = 0;
  }
  int query(int i) {
    i += 1;
    int sum = 0;
    while (i > 0) {
      sum += tree[i];
      i -= (i & -i);
    }
    return sum;
  }
  void update(int i, int dif) {
    i += 1;
    while (i < MX) {
      tree[i] += dif;
      i += (i & -i);
    }
  }
} FT;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout.precision(10);
  cout << fixed;
  for (int i = 0; i < MX; i++) parent[i] = i;
  for (int i = 0; i < MX; i++) L[i] = T[i] = -1;
  int n, m, u, v, w;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> U[i] >> V[i] >> W[i];
    u = U[i], v = V[i], w = W[i];
    if (findSet(u) != findSet(v)) {
      adj[u].push_back(v);
      pes[u].push_back(w);
      adj[v].push_back(u);
      pes[v].push_back(w);
      unionSet(u, v);
      ans[i] = true;
    }
  }
  for (int i = 1; i <= n; i++)
    if (L[i] == -1) {
      L[i] = 0;
      dfs(i);
    }
  build(n);
  for (int i = 0; i < m; i++) {
    u = U[i], v = V[i], w = W[i];
    if (ans[i]) {
      cout << "YES\n";
    } else {
      int lca_ = lca(u, v);
      int val = FT.query(pos[0][u]) + FT.query(pos[0][v]) -
                2 * FT.query(pos[0][lca_]);
      int xr = ((XOR[u] ^ XOR[v]) ^ w);
      if (val == 0 && xr == 1) {
        cout << "YES\n";
        while (u != lca_) {
          FT.update(pos[0][u], 1);
          FT.update(pos[1][u], -1);
          u = T[u];
        }
        while (v != lca_) {
          FT.update(pos[0][v], 1);
          FT.update(pos[1][v], -1);
          v = T[v];
        }
      } else {
        cout << "NO\n";
      }
    }
  }
  return 0;
}
