#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
struct SegTree {
  vector<pii> st;
  vector<pii> lazy;
  SegTree(int n) : st(4 * n + 1), lazy(4 * n + 1){};
  void push(int v) {
    for (int ch = v * 2; ch <= v * 2 + 1; ch++) {
      st[ch] = max(st[ch], lazy[v]);
      lazy[ch] = max(lazy[ch], lazy[v]);
    }
    lazy[v] = {0, 0};
  }
  void update(int v, int tl, int tr, int l, int r, pii val) {
    if (l > r) return;
    if (tl == l && tr == r) {
      st[v] = max(val, st[v]);
      lazy[v] = max(val, lazy[v]);
      return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, min(r, tm), val);
    update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
    st[v] = max(st[v * 2], st[v * 2 + 1]);
  }
  pii query(int v, int tl, int tr, int l, int r) {
    if (l > r) return {0, 0};
    if (tl == l && tr == r) return st[v];
    push(v);
    int tm = (tl + tr) / 2;
    pii ql = query(v * 2, tl, tm, l, min(r, tm));
    pii qr = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    return max(ql, qr);
  }
};
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  map<int, int> comp;
  vector<vector<pii>> seg(n + 1);
  for (int j = 0; j < m; j++) {
    int i, l, r;
    cin >> i >> l >> r;
    seg[i].push_back({l, r});
    comp[l] = 0;
    comp[r] = 0;
  }
  int num = 0;
  for (auto &[k, v] : comp) {
    v = ++num;
  }
  SegTree st(num);
  vector<int> to(n + 5);
  for (int i = 1; i <= n; i++) {
    pii mx = {0, 0};
    for (auto &[l, r] : seg[i]) {
      l = comp[l], r = comp[r];
      mx = max(mx, st.query(1, 1, num, l, r));
    }
    to[i] = mx.second;
    mx = {mx.first + 1, i};
    for (auto [l, r] : seg[i]) {
      st.update(1, 1, num, l, r, mx);
    }
  }
  auto [ans, r] = st.st[1];
  to[n + 1] = r;
  cout << n - ans << '\n';
  int rw = n + 1;
  while (rw) {
    for (int i = to[rw] + 1; i < rw; i++) cout << i << ' ';
    rw = to[rw];
  }
  cout << '\n';
  return 0;
}
