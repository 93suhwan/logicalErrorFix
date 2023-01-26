#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
vector<array<int, 3>> v[N];
int enjoy[N];
int lvl[N];
int dad[N];
int vlim[N][18];
int tmax[N][18];
bool vis[N];
int sz[N];
void find_sz(int a, int p) {
  sz[a] = 1;
  for (auto [to, c, t] : v[a]) {
    if (to == p || vis[to]) continue;
    find_sz(to, a);
    sz[a] += sz[to];
  }
}
int find_centroid(int a, int p, int n) {
  for (auto [to, c, t] : v[a]) {
    if (to == p || vis[to]) continue;
    if (sz[to] > n / 2) return find_centroid(to, a, n);
  }
  return a;
}
void find_d(int a, int p, int l) {
  for (auto [to, c, t] : v[a]) {
    if (to == p || vis[to]) continue;
    vlim[to][l] = min(vlim[a][l], c);
    tmax[to][l] = max(tmax[a][l], t);
    find_d(to, a, l);
  }
}
void build_cd(int a, int p) {
  find_sz(a, 0);
  int centroid = find_centroid(a, 0, sz[a]);
  dad[centroid] = p;
  vis[centroid] = 1;
  lvl[centroid] = (p != 0 ? lvl[p] + 1 : 0);
  vlim[centroid][lvl[centroid]] = (1 << 30);
  find_d(centroid, 0, lvl[centroid]);
  for (auto [to, c, t] : v[centroid])
    if (!vis[to]) build_cd(to, centroid);
}
struct obj {
  map<int, array<int, 2>> m;
  void add(int lim, int e, int t) {
    array<int, 2> now = {e, t};
    auto it = m.lower_bound(lim);
    if (it != m.end() && now <= (*it).second) return;
    while (it != m.begin()) {
      array<int, 2> tmp = (*prev(it)).second;
      if (tmp <= now)
        m.erase(prev(it));
      else
        break;
    }
    m[lim] = now;
  }
  array<int, 2> qry(int lim) { return (*m.lower_bound(lim)).second; }
};
obj opt[N];
void add(int a) {
  int e = enjoy[a];
  int p = a;
  while (p != 0) {
    opt[p].add(vlim[a][lvl[p]], e, tmax[a][lvl[p]]);
    p = dad[p];
  }
}
array<int, 2> query(int a, int lim) {
  array<int, 2> res = {0, 0};
  int p = a;
  while (p != 0) {
    if (vlim[a][lvl[p]] >= lim) res = max(res, opt[p].qry(lim));
    p = dad[p];
  }
  return res;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> enjoy[i];
  for (int i = 1; i <= n - 1; i++) {
    int a, b, c, t;
    cin >> a >> b >> c >> t;
    v[a].push_back({b, c, t});
    v[b].push_back({a, c, t});
  }
  build_cd(1, 0);
  for (int i = 1; i <= n; i++) add(i);
  while (q--) {
    int a, lim;
    cin >> lim >> a;
    auto [e, t] = query(a, lim);
    cout << e << " " << t << "\n";
  }
  return 0;
}
