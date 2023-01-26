#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct item {
  int mx;
};
struct segtree {
  int sz;
  vector<item> values;
  void init(int n) {
    sz = 1;
    while (sz < n) sz *= 2;
    values.resize(2 * sz, NEUTRAL_ELEMENT);
  }
  item NEUTRAL_ELEMENT = {0};
  item merge(item a, item b) { return {max(a.mx, b.mx)}; }
  item single(int v) { return {v}; }
  void build(vector<int> &a, int x, int lx, int rx) {
    if (rx - lx == 1) {
      if (lx < (int)a.size()) {
        values[x] = single(a[lx]);
      }
      return;
    }
    int m = (lx + rx) / 2;
    build(a, 2 * x + 1, lx, m);
    build(a, 2 * x + 2, m, rx);
    values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
  }
  void build(vector<int> &a) { build(a, 0, 0, sz); }
  void set(int i, int v, int x, int lx, int rx) {
    if (rx - lx == 1) {
      values[x] = merge(single(v), values[x]);
      return;
    }
    int m = (lx + rx) / 2;
    if (i < m) {
      set(i, v, 2 * x + 1, lx, m);
    } else {
      set(i, v, 2 * x + 2, m, rx);
    }
    values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
  }
  void set(int i, int v) { set(i, v, 0, 0, sz); }
  item calc(int l, int r, int x, int lx, int rx) {
    if (l >= rx || lx >= r) return NEUTRAL_ELEMENT;
    if (lx >= l && rx <= r) return values[x];
    int m = (lx + rx) / 2;
    item s1 = calc(l, r, 2 * x + 1, lx, m);
    item s2 = calc(l, r, 2 * x + 2, m, rx);
    return merge(s1, s2);
  }
  item calc(int l, int r) { return calc(l, r, 0, 0, sz); }
};
void solve() {
  int n;
  cin >> n;
  int a[n + 1];
  a[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<int> v[n + 1];
  for (int i = n; i >= 1; i--) {
    if (i - a[i] + 1 >= 0) v[i - a[i] + 1].push_back(i);
  }
  segtree st;
  st.init(N);
  for (int i = n; i >= 1; i--) {
    sort(v[i].begin(), v[i].end());
    reverse(v[i].begin(), v[i].end());
    for (int j : v[i]) {
      int mx = st.calc(a[j] + 1, N).mx;
      st.set(a[j], mx + 1);
    }
  }
  cout << st.calc(0, N).mx << "\n";
}
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int t;
  t = 1;
  while (t--) {
    solve();
  }
}
