#include <bits/stdc++.h>
using namespace std;
using ui = unsigned;
const ui N = 1e5 + 4, inf = 4e9;
set<pair<ui, ui>> s[N];
set<tuple<ui, ui, ui>> a;
map<pair<ui, ui>, ui> mp;
ui c[N];
void add(ui x) {
  ui i = 0, y;
  for (auto o = s[x].begin(); o != s[x].end() && i < 4; ++o, ++i)
    if (c[y = o->second] < 4) ++c[y], a.emplace(o->first, y, x);
}
void del(ui x) {
  ui i = 0;
  for (auto o = s[x].begin(); o != s[x].end() && i < 4; ++o, ++i) {
    auto u = a.find(make_tuple(o->first, o->second, x));
    if (u != a.end()) a.erase(u), --c[o->second];
  }
}
void add(ui x, ui y, ui z) {
  mp[{x, y}] = z, del(x), s[x].emplace(z, y), add(x);
}
void del(ui x, ui y) { del(x), s[x].erase({mp[{x, y}], y}), add(x); }
ui get(ui x) {
  if (s[x].size() < 4) return inf;
  ui i = 0, w = 0;
  for (auto o = s[x].begin(); i < 4; ++o, ++i) w += o->first;
  return w;
}
ui g1(ui x, ui y) {
  if (s[x].size() < 2 || s[y].size() < 2) return inf;
  auto o1 = ++s[x].begin(), o2 = ++s[y].begin();
  if (o1->second != o2->second) return o1->first + o2->first;
  ui w = inf;
  if (s[x].size() > 2) w = next(o1)->first + o2->first;
  if (s[y].size() > 2) w = min(w, o1->first + next(o2)->first);
  return w;
}
ui g2(ui x, ui y, ui z) {
  ui u, v, w;
  int cnt = 0;
  for (auto o : a) {
    tie(w, u, v) = o;
    if (u != x && u != y && v != x && v != y) {
      return w + z;
    }
  }
  return inf;
}
void cal() {
  ui z, x, y;
  tie(z, x, y) = *a.begin(),
            cout << min(get(x), min(get(y), min(g1(x, y), g2(x, y, z))))
                 << '\n';
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0);
  ui n, m, q, i, j, k;
  for (cin >> n >> m; m--;) cin >> i >> j >> k, add(i, j, k), add(j, i, k);
  for (cin >> q; cal(), q--;)
    if (cin >> i >> j >> k, i)
      cin >> i, add(j, k, i), add(k, j, i);
    else
      del(j, k), del(k, j);
  return 0;
}
