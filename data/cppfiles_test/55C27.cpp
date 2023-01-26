#include <bits/stdc++.h>
using namespace std;
struct segtree {
  int size = 1;
  vector<pair<int, int>> v;
  vector<pair<int, int>> lazy;
  void init(int n) {
    while (n > size) {
      size *= 2;
    }
    v.assign(size * 2, {0, -1});
    lazy.assign(size * 2, {0, -1});
  }
  void prop(int x, int lx, int rx) {
    if (rx - lx == 1) return;
    if (lazy[x] == make_pair(0, -1)) return;
    v[x * 2 + 1] = lazy[x];
    v[x * 2 + 2] = lazy[x];
    lazy[x * 2 + 1] = lazy[x];
    lazy[x * 2 + 2] = lazy[x];
    lazy[x] = {0, -1};
  }
  void update(int l, int r, pair<int, int> val, int x, int lx, int rx) {
    prop(x, lx, rx);
    if (rx <= l || lx >= r) {
      return;
    }
    if (lx >= l && rx <= r) {
      v[x] = val;
      lazy[x] = val;
      return;
    }
    int m = (lx + rx) / 2;
    update(l, r, val, x * 2 + 1, lx, m);
    update(l, r, val, x * 2 + 2, m, rx);
    v[x] = max(v[x * 2 + 1], v[x * 2 + 2]);
  }
  void update(int l, int r, pair<int, int> val) {
    update(l, r + 1, val, 0, 0, size);
  }
  pair<int, int> get(int l, int r, int x, int lx, int rx) {
    prop(x, lx, rx);
    if (rx <= l || lx >= r) {
      return {0, -1};
    }
    if (lx >= l && rx <= r) {
      return v[x];
    }
    int m = (lx + rx) / 2;
    pair<int, int> m1 = get(l, r, x * 2 + 1, lx, m);
    pair<int, int> m2 = get(l, r, x * 2 + 2, m, rx);
    return max(m1, m2);
  }
  pair<int, int> get(int l, int r) { return get(l, r + 1, 0, 0, size); }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  set<int> s;
  vector<vector<pair<int, int>>> v(n);
  vector<tuple<int, int, int>> actions;
  for (int i = 0; i < m; i++) {
    int j, l, r;
    cin >> j >> l >> r;
    j--;
    actions.push_back({j, l, r});
    s.insert(l);
    s.insert(r);
    v[j].push_back(make_pair(l, r));
  }
  auto s1 = s.begin();
  auto s2 = s.begin();
  if (s2 != s.end()) s2++;
  map<int, int> mapa;
  int ctr = 0;
  mapa[*s1] = ctr;
  ctr++;
  while (s2 != s.end()) {
    if ((*s1) != (*s2)) {
      mapa[*s2] = ctr;
      ctr++;
    }
    s1++;
    s2++;
  }
  segtree prev;
  prev.init(2 * m + 2);
  vector<int> before(n, -1);
  for (int i = 0; i < n; i++) {
    pair<int, int> mx = {0, -1};
    for (auto x : v[i]) {
      int a = mapa[x.first];
      int b = mapa[x.second];
      mx = max(mx, prev.get(a, b));
    }
    mx.first++;
    before[i] = mx.second;
    mx.second = i;
    for (auto x : v[i]) {
      int a = mapa[x.first];
      int b = mapa[x.second];
      prev.update(a, b, mx);
    }
  }
  vector<int> ok(n, false);
  int lastmx = prev.get(0, 2 * m + 1).second;
  while (lastmx >= 0) {
    ok[lastmx] = true;
    lastmx = before[lastmx];
  }
  vector<int> res;
  int resnum = 0;
  for (int i = 0; i < n; i++) {
    if (!ok[i]) {
      res.push_back(i);
      resnum++;
    }
  }
  cout << resnum << '\n';
  for (auto w : res) cout << w + 1 << " ";
}
