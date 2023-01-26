#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 17, lg = 18;
int n, q, cpar[maxn], sz[maxn], che[maxn], wi[maxn][lg], cst[maxn][lg],
    par[maxn], e[maxn];
map<int, pair<int, int> > o;
vector<pair<int, pair<int, int> > > g[maxn];
vector<pair<int, int> > qs[maxn];
pair<int, int> ans[maxn];
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
void setD(vector<pair<int, pair<int, int> > > &pp, int v, int p, int cw,
          int cc) {
  if (mark[v]) return;
  pp.push_back({cw, {e[v], cc}});
  for (auto e : g[v])
    if (e.first != p)
      setD(pp, e.first, v, min(cw, e.second.first), max(cc, e.second.second));
  for (auto &[x, i] : qs[v])
    if (cw >= x) {
      auto it = o.lower_bound(x);
      if (it != o.end())
        ans[i] = max(ans[i], {it->second.first, max(it->second.second, cc)});
    }
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
  for (int times = 0; times < 2; ++times) {
    o = {{INT_MAX, {e[v], 0}}};
    for (auto [u, w] : g[v]) {
      if (mark[u]) continue;
      vector<pair<int, pair<int, int> > > tmp;
      setD(tmp, u, v, w.first, w.second);
      for (auto [w, od] : tmp) {
        auto it = o.lower_bound(w);
        if (it != o.end() && it->second >= od) continue;
        o.erase(w);
        it = o.insert({w, od}).first;
        while (it != o.begin() && prev(it)->second <= od) o.erase(prev(it));
      }
    }
    for (auto &[x, i] : qs[v]) {
      auto it = o.lower_bound(x);
      if (it != o.end()) ans[i] = max(ans[i], it->second);
    }
    reverse(g[v].begin(), g[v].end());
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
  for (int i = 0; i < q; ++i) {
    int v, x;
    cin >> x >> v;
    qs[--v].emplace_back(x, i);
  }
  prep();
  cpar[get_cent()] = -1;
  for (int i = 0; i < q; ++i)
    cout << ans[i].first << ' ' << ans[i].second << '\n';
}
