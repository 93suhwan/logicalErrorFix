#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 17, lg = 18;
int n, q, cpar[maxn], sz[maxn], che[maxn], wi[maxn][lg], cst[maxn][lg],
    par[maxn], e[maxn];
vector<pair<int, pair<int, int> > > o[maxn];
vector<pair<int, pair<int, int> > > g[maxn];
map<pair<int, int>, int> mc;
bool mark[maxn];
void prep(int v = 0, int p = 0) {
  sz[v] = 1;
  for (auto e : g[v])
    if (e.first != p) {
      par[e.first] = v;
      prep(e.first, v);
      sz[v] += sz[e.first];
    }
}
void setD(int v, int lvl, int p = -1, int cw = INT_MAX, int cc = 0) {
  if (mark[v]) return;
  wi[v][lvl] = cw;
  cst[v][lvl] = cc;
  mc[{cw, e[v]}] = max(mc[{cw, e[v]}], cc);
  for (auto e : g[v])
    if (e.first != p)
      setD(e.first, lvl, v, min(cw, e.second.first), max(cc, e.second.second));
}
int get_cent(int root = 0, int h = 0) {
  int v = root, size = sz[root];
  bool done = 0;
  while (done ^= 1)
    for (auto &e : g[v])
      if (e.first != par[v] && sz[e.first] > (size >> 1)) {
        v = e.first, done = 0;
        break;
      }
  che[v] = h;
  setD(v, h);
  {
    for (auto &[k, cost] : mc) o[v].push_back({k.first, {k.second, cost}});
    mc.clear();
    sort(o[v].begin(), o[v].end());
    int sz = 0;
    for (auto &el : o[v]) {
      while (sz && o[v][sz - 1].second <= el.second) --sz;
      o[v][sz++] = el;
    }
    o[v].resize(sz);
  }
  mark[v] = 1;
  int mysz = sz[v];
  for (int u = v;; u = par[u]) {
    sz[u] -= mysz;
    if (u == root) break;
  }
  for (auto &e : g[v])
    if (e.first != par[v] && sz[e.first]) {
      int x = get_cent(e.first, h + 1);
      cpar[x] = v;
    }
  if (v != root) {
    int x = get_cent(root, h + 1);
    cpar[x] = v;
  }
  return v;
}
pair<int, int> get(int v, int x) {
  pair<int, int> ans;
  for (int u = v; u != -1; u = cpar[u]) {
    if (wi[v][che[u]] < x) continue;
    auto it = lower_bound(o[u].begin(), o[u].end(),
                          pair<int, pair<int, int> >{x, {0, 0}});
    if (it == o[u].end()) continue;
    ans = max(ans, {it->second.first, max(it->second.second, cst[v][che[u]])});
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  cin >> n >> q;
  for (int i = 0; i < n; ++i) cin >> e[i];
  for (int i = 0; i < n - 1; ++i) {
    int a, b, c, t;
    cin >> a >> b >> c >> t;
    --a;
    --b;
    g[a].push_back({b, {c, t}});
    g[b].push_back({a, {c, t}});
  }
  prep();
  cpar[get_cent()] = -1;
  while (q--) {
    int v, x;
    cin >> x >> v;
    auto b = get(--v, x);
    cout << b.first << ' ' << b.second << '\n';
  }
}
