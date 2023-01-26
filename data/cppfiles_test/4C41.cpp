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
const int N = 2e5 + 1;
const int M = 1e9 + 7;
void add(int &a, int b) {
  a += b;
  if (a >= M)
    a -= M;
  else if (a < 0)
    a += M;
}
int sum(int a, int b) {
  add(a, b);
  return a;
}
int mult(int a, int b) { return 1ll * a * b % M; }
int binpow(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = mult(ans, a);
    b >>= 1;
    a = mult(a, a);
  }
  return ans;
}
vector<pair<int, int>> g[N];
vector<int> cord;
vector<array<int, 4>> cen[N];
struct mypref {
  vector<pair<int, int>> xs;
  vector<int> prefs;
  void build() {
    sort((xs).begin(), (xs).end());
    vector<pair<int, int>> vc;
    for (auto &z : xs) {
      if (!(int)(vc).size() || vc.back().first != z.first)
        vc.push_back({z.first, z.second});
      else
        add(vc.back().second, z.second);
    }
    for (int i = 0; i < (int)(vc).size(); i++) prefs.push_back(vc[i].second);
    for (int i = 1; i < (int)(vc).size(); i++) add(prefs[i], prefs[i - 1]);
    xs = vc;
  }
  int get(int id) {
    int l = 0, r = (int)(xs).size();
    while (l != r) {
      int tm = (l + r) >> 1;
      if (xs[tm].first > id)
        r = tm;
      else
        l = tm + 1;
    }
    l--;
    id = l;
    if (id == -1) return 0;
    return prefs[id];
  }
};
vector<mypref> pref1[N][2];
vector<mypref> prefas[N][2];
mypref PREF1[N][2];
mypref PREFas[N][2];
int dp[N], a[N], was[N], last[N], k;
int ans = 0;
void calc_sizes(int v, int p) {
  dp[v] = 1;
  for (auto &z : g[v]) {
    if (was[z.first] || z.first == p) continue;
    calc_sizes(z.first, v);
    dp[v] += dp[z.first];
  }
}
int get_centroid(int v, int p, int szz) {
  for (auto &z : g[v]) {
    if (z.first == p || was[z.first]) continue;
    if (dp[z.first] >= szz / 2) return get_centroid(z.first, v, szz);
  }
  return v;
}
void dfs_down(int v, int fi, int lst, int sm, int cost, int p, int tt) {
  add(sm, a[v]);
  if (cost <= k) add(ans, sm);
  if (cost <= k) add(ans, sm);
  cen[v].push_back({cen[p].back()[0], cost, fi, sum(sm, -a[cen[p].back()[0]])});
  pref1[cen[v].back()[0]][fi][tt].xs.push_back({cost, 1});
  prefas[cen[v].back()[0]][fi][tt].xs.push_back({cost, sm});
  PREF1[cen[v].back()[0]][fi].xs.push_back({cost, 1});
  PREFas[cen[v].back()[0]][fi].xs.push_back({cost, sm});
  last[v] = tt;
  for (auto &z : g[v]) {
    if (was[z.first] || z.first == p) continue;
    dfs_down(z.first, fi, z.second, sm, cost + (lst != z.second), v, tt);
  }
}
void get(int v) {
  int j = (int)(cen[v]).size() - 1, id = -1;
  while (1) {
    if (id != -1) {
      int first = cen[v][j][2];
      int me = cen[v][j][3];
      int ce = cen[v][j][0];
      for (int second = 0; second < 2; second++) {
        int how = k - (first != second) - cen[v][j][1];
        int hex = 0;
        add(hex, -mult(me, pref1[ce][second][id].get(how)));
        add(hex, -prefas[ce][second][id].get(how));
        add(hex, mult(me, PREF1[ce][second].get(how)));
        add(hex, PREFas[ce][second].get(how));
        add(ans, hex);
      }
    }
    id = last[cen[v][j][0]];
    j--;
    if (j < 0) break;
  }
}
void build(int v) {
  calc_sizes(v, v);
  v = get_centroid(v, v, dp[v]);
  was[v] = 1;
  cen[v].push_back({v, 0, -1, a[v]});
  int how = 0;
  for (auto &z : g[v])
    if (!was[z.first]) ++how;
  for (int j = 0; j < 2; j++) pref1[v][j].resize(how), prefas[v][j].resize(how);
  how = 0;
  for (auto &z : g[v]) {
    if (was[z.first]) continue;
    dfs_down(z.first, z.second, z.second, a[v], 0, v, how);
    pref1[v][0][how].build();
    pref1[v][1][how].build();
    prefas[v][0][how].build();
    prefas[v][1][how].build();
    ++how;
  }
  PREF1[v][0].build();
  PREF1[v][1].build();
  PREFas[v][0].build();
  PREFas[v][1].build();
  for (auto &z : g[v]) {
    if (!was[z.first]) build(z.first);
  }
}
signed main() {
  INPUT();
  int n;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 1; i < n; i++) {
    int v, u, c;
    cin >> v >> u >> c;
    --v;
    --u;
    g[v].push_back({u, c});
    g[u].push_back({v, c});
  }
  build(0);
  for (int i = 0; i < n; i++) get(i);
  int obr = binpow(2, M - 2);
  ans = mult(ans, obr);
  for (int i = 0; i < n; i++) add(ans, a[i]);
  cout << ans;
  return 0;
}
