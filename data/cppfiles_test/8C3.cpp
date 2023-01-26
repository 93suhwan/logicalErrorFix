#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T &a, const T &b) {
  return (a > b ? a = b, 1 : 0);
}
template <class T>
bool umax(T &a, const T &b) {
  return (a < b ? a = b, 1 : 0);
}
void INPUT(bool F = 0) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  if (F) {
    freopen(
        "name"
        ".in",
        "r", stdin);
    freopen(
        "name"
        ".out",
        "w", stdout);
  }
}
const int mod = (int)1e9 + 7;
const int N = (int)1e5 + 15;
const int LG = (int)17;
vector<int> g[N];
int a[N], up[N][LG], tin[N], tout[N], T = 2;
long long h[N], fen[N];
bool anc(int u, int v) { return (tin[u] <= tin[v]) && (tout[u] >= tout[v]); }
void dfs(int v, int p, long long H) {
  up[v][0] = p;
  tin[v] = T++;
  H += a[v];
  h[v] = H;
  for (int i = 1; i < LG; ++i) up[v][i] = up[up[v][i - 1]][i - 1];
  for (auto u : g[v]) {
    if (u != p) {
      dfs(u, v, H);
    }
  }
  tout[v] = T - 1;
}
void modify(int x, long long pl) {
  for (; x < N; x += x & -x) fen[x] += pl;
}
long long get(int r) {
  long long ans = 0;
  for (; r > 0; r -= r & -r) {
    ans += fen[r];
  }
  return ans;
}
int get_lca(int u, int v) {
  if (anc(u, v)) return u;
  if (anc(v, u)) return v;
  for (int i = LG - 1; i >= 0; --i) {
    if (!anc(up[u][i], v)) u = up[u][i];
  }
  return up[u][0];
}
void change(int v, int val) {
  val = abs(val);
  int diff = val - a[v];
  a[v] = val;
  modify(tin[v], +diff);
  modify(tout[v] + 1, -diff);
}
long long gh(int v) { return get(tin[v]); }
long long query(int u, int v) {
  if (anc(v, u)) swap(v, u);
  if (anc(u, v)) {
    long long ans = (gh(v) - gh(u)) * 2 - a[v] + a[u];
    return ans;
  }
  int lca = get_lca(u, v);
  long long ans =
      (gh(u) - gh(lca)) * 2 + (gh(v) - gh(lca)) * 2 - a[u] - a[v] + 2 * a[lca];
  return ans;
}
signed main() {
  INPUT();
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; ++i) cin >> a[i], a[i] = abs(a[i]);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0, 0, 0);
  for (int i = 0; i < n; ++i) {
    modify(tin[i], h[i]);
    modify(tin[i] + 1, -h[i]);
  }
  for (int i = 0; i < q; ++i) {
    int t, u, c;
    cin >> t >> u >> c;
    --u;
    if (t == 1) {
      change(u, c);
    } else {
      --c;
      cout << query(u, c) << '\n';
    }
  }
  return 0;
}
