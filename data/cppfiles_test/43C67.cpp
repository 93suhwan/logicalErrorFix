#include <bits/stdc++.h>
using namespace std;
long long power(long long a, long long b, long long md) {
  return (!b ? 1
             : (b & 1 ? a * power(a * a % md, b / 2, md) % md
                      : power(a * a % md, b / 2, md) % md));
}
const int xn = 4e5 + 10;
const int xm = 10 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const long long INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;
int n, q, a[xn], par[xn], sz[xn], ptr, pt, W;
int P[xm][xn], mxedge[xm][xn], H[xn], c[xn];
pair<int, int> b[xn], f[xn], ans[xn];
vector<pair<pair<int, int>, pair<int, int> > > E;
vector<int> compress;
vector<pair<int, int> > adj[xn], query[xn];
unordered_map<int, int> mp;
void DFS(int v) {
  for (int i = 1; i < xm; ++i) {
    P[i][v] = P[i - 1][P[i - 1][v]];
    mxedge[i][v] = max(mxedge[i - 1][v], mxedge[i - 1][P[i - 1][v]]);
  }
  for (pair<int, int> u : adj[v]) {
    if (u.first == P[0][v]) continue;
    H[u.first] = H[v] + 1;
    P[0][u.first] = v;
    mxedge[0][u.first] = u.second;
    DFS(u.first);
  }
}
int LCA(int v, int u) {
  if (H[v] > H[u]) swap(v, u);
  int res = 0;
  for (int i = xm - 1; i >= 0; --i) {
    if ((1 << i) > H[u] - H[v]) continue;
    res = max(res, mxedge[i][u]);
    u = P[i][u];
  }
  if (v == u) return res;
  for (int i = xm - 1; i >= 0; --i) {
    if (P[i][v] == P[i][u]) continue;
    res = max(res, mxedge[i][v]);
    res = max(res, mxedge[i][u]);
    v = P[i][v], u = P[i][u];
  }
  return max({res, mxedge[0][v], mxedge[0][u]});
}
void buildDSU() {
  for (int i = 1; i <= n; ++i) {
    par[i] = i;
    sz[i] = 1;
    f[i] = {a[i], i};
  }
}
int get_root(int v) {
  if (par[v] == v) return v;
  return par[v] = get_root(par[v]);
}
int get(int v) { return LCA(v, f[get_root(v)].second); }
void merge(int v, int u, int w) {
  int pv = v, pu = u;
  v = get_root(v);
  u = get_root(u);
  if (sz[v] < sz[u]) swap(v, u), swap(pv, pu);
  if (f[v].first == f[u].first)
    c[v] = max({c[v], c[u], get(pv), get(pu), w});
  else if (f[v].first < f[u].first)
    f[v] = f[u], c[v] = c[u];
  par[u] = v, sz[v] += sz[u];
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 0; i < n - 1; ++i) {
    int v, u, x, y;
    cin >> v >> u >> x >> y;
    E.push_back({{x, y}, {v, u}});
    compress.push_back(x);
  }
  for (int i = 0; i < q; ++i) {
    int x, v;
    cin >> x >> v;
    b[i] = {v, x};
    compress.push_back(x);
  }
  sort(compress.begin(), compress.end());
  for (int i = 0; i < int(compress.size()); ++i)
    if (!i || compress[i] != compress[i - 1]) mp[compress[i]] = ptr++;
  for (int i = 0; i < n - 1; ++i) {
    E[i].first.first = mp[E[i].first.first];
    int v = E[i].second.first, u = E[i].second.second, w = E[i].first.second;
    adj[v].push_back({u, w});
    adj[u].push_back({v, w});
  }
  for (int i = 0; i < q; ++i) {
    int v = b[i].first, x = b[i].second;
    query[mp[x]].push_back({v, i});
  }
  sort(E.begin(), E.end()), reverse(E.begin(), E.end());
  DFS(1), buildDSU();
  for (W = ptr - 1; W >= 0; --W) {
    while (pt < int(E.size()) && E[pt].first.first == W)
      merge(E[pt].second.first, E[pt].second.second, E[pt].first.second), ++pt;
    for (pair<int, int> x : query[W])
      ans[x.second] = {f[get_root(x.first)].first,
                       max(get(x.first), c[get_root(x.first)])};
  }
  for (int i = 0; i < q; ++i)
    cout << ans[i].first << ' ' << ans[i].second << '\n';
  return 0;
}
