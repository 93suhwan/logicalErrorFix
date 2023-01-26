#include <bits/stdc++.h>
using namespace std;
void FAST_IO(string filein = "", string fileout = "", string fileerr = "") {
  if (fopen(filein.c_str(), "r")) {
    freopen(filein.c_str(), "r", stdin);
    freopen(fileout.c_str(), "w", stdout);
  }
  cin.tie(0), cout.tie(0)->sync_with_stdio(0);
}
void Hollwo_Pelw();
signed main() {
  FAST_IO("hollwo_pelw.inp", "hollwo_pelw.out");
  int testcases = 1;
  for (int test = 1; test <= testcases; test++) {
    Hollwo_Pelw();
  }
  return 0;
}
const int N = 3e5 + 5;
int n, m, q, h[N], par[N], vis[N], val[N];
vector<int> adj[N];
void dfs(int u, int p) {
  vis[u] = 1;
  par[u] = p;
  for (int v : adj[u])
    if (!vis[v]) {
      h[v] = h[u] + 1;
      dfs(v, u);
    }
}
int update(int u, int v) {
  if (h[u] > h[v]) swap(u, v);
  while (h[v] > h[u]) {
    val[v] ^= 1;
    v = par[v];
  }
  if (u == v) return u;
  while (par[u] != par[v]) {
    val[u] ^= 1;
    val[v] ^= 1;
    u = par[u];
    v = par[v];
  }
  return par[u];
}
void print(int u, int v, int l) {
  vector<int> a, b;
  while (u != l) a.push_back(u), u = par[u];
  while (v != l) b.push_back(v), v = par[v];
  reverse(b.begin(), b.end());
  cout << a.size() + b.size() + 1 << '\n';
  for (auto x : a) cout << x << ' ';
  cout << l << ' ';
  for (auto x : b) cout << x << ' ';
  cout << '\n';
}
int res, cnt[N];
void Hollwo_Pelw() {
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 0);
  cin >> q;
  vector<tuple<int, int, int>> query(q);
  for (auto &[u, v, w] : query) {
    cin >> u >> v;
    w = update(u, v);
  }
  for (int _ = 1; _ <= n; _++)
    if (val[_]) {
      cout << "NO\n";
      for (int i = 1; i <= n; i++) cnt[par[i]] += val[i];
      for (int i = 1; i <= n; i++) {
        res += cnt[i] / 2;
        if (!val[i]) res += cnt[i] % 2;
      }
      cout << res;
      return;
    }
  cout << "YES\n";
  for (auto [u, v, w] : query) print(u, v, w);
}
