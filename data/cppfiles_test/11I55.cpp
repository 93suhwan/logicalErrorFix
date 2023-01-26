#include <bits/stdc++.h>
using namespace std;
template <class T>
struct SegTree {
  int n;
  vector<T> t;
  T E = -1e9;
  T comb(T a, T b) { return max(a, b); }
  SegTree() {}
  SegTree(int _n) : n(_n) { t.assign(4 * n + 5, E); }
  SegTree(vector<T>& bld) : n(bld.size()) {
    t.assign(4 * n + 5, E);
    build(bld, 1, 0, n - 1);
  }
  void build(vector<T>& bld, int node, int tl, int tr) {
    if (tl == tr) {
      t[node] = bld[tl];
    } else {
      int tm = (tl + tr) / 2;
      build(bld, 2 * node, tl, tm);
      build(bld, 2 * node + 1, tm + 1, tr);
      pull(node);
    }
  }
  void pull(int node) { t[node] = comb(t[2 * node], t[2 * node + 1]); }
  T query(int l, int r) { return query(l, r, 1, 0, n - 1); }
  T query(int l, int r, int node, int tl, int tr) {
    if (r < tl || tr < l) return E;
    if (l <= tl && tr <= r) return t[node];
    int tm = (tl + tr) / 2;
    return comb(query(l, r, 2 * node, tl, tm),
                query(l, r, 2 * node + 1, tm + 1, tr));
  }
  void update(int p, T val) { return update(p, val, 1, 0, n - 1); }
  void update(int p, T val, int node, int tl, int tr) {
    if (tl == tr) {
      t[node] = max(val, t[node]);
      return;
    }
    int tm = (tl + tr) / 2;
    if (p <= tm)
      update(p, val, 2 * node, tl, tm);
    else
      update(p, val, 2 * node + 1, tm + 1, tr);
    pull(node);
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  const int OFF = 2e5 + 7;
  const int MX = 2 * OFF;
  vector<int> a(n);
  vector<vector<int>> idxs(MX);
  SegTree<int> T(MX);
  T.update(OFF, 0);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    idxs[a[i]].push_back(i + 1);
  }
  int ans = 0;
  for (int val = 0; val < MX; val++) {
    auto& v = idxs[val];
    if (v.empty()) continue;
    for (auto& i : v) {
      int bst = T.query(OFF + val - i, MX - 1) + 1;
      T.update(OFF + val - i, bst);
      ans = max(ans, bst);
    }
  }
  cout << ans << '\n';
}
