#include <bits/stdc++.h>
using namespace std;
struct segtree {
  int size = 1;
  vector<int> v;
  vector<int> lazy;
  void init(int n) {
    while (n > size) {
      size *= 2;
    }
    v.assign(size * 2, -1);
    lazy.assign(size * 2, -1);
  }
  void prop(int x, int lx, int rx) {
    if (rx - lx == 1) return;
    if (lazy[x] == -1) return;
    v[x * 2 + 1] = lazy[x];
    v[x * 2 + 2] = lazy[x];
    lazy[x * 2 + 1] = lazy[x];
    lazy[x * 2 + 2] = lazy[x];
    lazy[x] = -1;
  }
  void update(int l, int r, int val, int x, int lx, int rx) {
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
  void update(int l, int r, int val) { update(l, r + 1, val, 0, 0, size); }
  int get(int l, int r, int x, int lx, int rx) {
    prop(x, lx, rx);
    if (rx <= l || lx >= r) {
      return -1;
    }
    if (lx >= l && rx <= r) {
      return v[x];
    }
    int m = (lx + rx) / 2;
    int m1 = get(l, r, x * 2 + 1, lx, m);
    int m2 = get(l, r, x * 2 + 2, m, rx);
    return max(m1, m2);
  }
  int get(int l, int r) { return get(l, r + 1, 0, 0, size); }
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
  vector<pair<int, int>> todelete;
  vector<int> res;
  set<int> good;
  for (int i = 0; i < n; i++) {
    for (auto [a, b] : v[i]) {
      a = mapa[a];
      b = mapa[b];
      if (prev.get(a, b) <= -1) {
        prev.update(a, b, i);
        todelete.push_back(make_pair(a, b));
      } else {
        int pref = prev.get(a, b);
        res.push_back(pref);
        good.insert(pref);
        good.insert(i);
        for (auto w : todelete) {
          prev.update(w.first, w.second, -2);
        }
        todelete.clear();
        break;
      }
    }
    if (todelete.empty()) {
      for (auto [a, b] : v[i]) {
        a = mapa[a];
        b = mapa[b];
        prev.update(a, b, i);
      }
    }
  }
  int resnum = 0;
  vector<int> final;
  for (int i = 0; i < n; i++) {
    if (good.find(i) == good.end()) {
      final.push_back(i);
      resnum++;
    }
  }
  cout << resnum << '\n';
  for (auto w : final) {
    cout << w + 1 << " ";
  }
}
