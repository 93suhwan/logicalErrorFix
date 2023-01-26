#include <bits/stdc++.h>
using namespace std;
struct segment {
  int row, l, r;
};
const int INF = 1e9;
struct SegTree {
  const pair<int, int> NOOP = {INF, INF};
  SegTree(int _n) {
    n = _n;
    size = 1;
    while (size < _n) size *= 2;
    t.resize(2 * size, NOOP);
    p.resize(2 * size, NOOP);
  }
  void apply_op(pair<int, int> &a, const pair<int, int> &op) {
    if (op == NOOP) return;
    if (a == NOOP) {
      a = op;
      return;
    }
    a = min(a, op);
  }
  pair<int, int> merge(const pair<int, int> &A, const pair<int, int> &B) {
    return min(A, B);
  }
  void push(int x) {
    if (x >= size - 1 || p[x] == NOOP) return;
    apply_op(p[2 * x + 1], p[x]);
    apply_op(t[2 * x + 1], p[x]);
    apply_op(p[2 * x + 2], p[x]);
    apply_op(t[2 * x + 2], p[x]);
    p[x] = NOOP;
  }
  void upd(int x, int lx, int rx, int l, int r, const pair<int, int> &val) {
    if (rx <= l || r <= lx) return;
    if (l <= lx && rx <= r) {
      apply_op(p[x], val);
      apply_op(t[x], val);
      return;
    }
    push(x);
    int mid = (lx + rx) / 2;
    upd(2 * x + 1, lx, mid, l, r, val);
    upd(2 * x + 2, mid, rx, l, r, val);
    t[x] = merge(t[2 * x + 1], t[2 * x + 2]);
  }
  pair<int, int> query(int x, int lx, int rx, int l, int r) {
    if (rx <= l || r <= lx) return NOOP;
    if (l <= lx && rx <= r) return t[x];
    push(x);
    int mid = (lx + rx) / 2;
    pair<int, int> res1 = query(2 * x + 1, lx, mid, l, r);
    pair<int, int> res2 = query(2 * x + 2, mid, rx, l, r);
    return merge(res1, res2);
  }
  void upd(int l, int r, const pair<int, int> &val) {
    upd(0, 0, size, l, r, val);
  }
  pair<int, int> query(int l, int r) { return query(0, 0, size, l, r); }
  int size, n;
  vector<pair<int, int>> t, p;
};
int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<segment> ss(m);
  vector<pair<int, int>> ls(m), rs(m);
  vector<int> endpoints;
  for (int i = 0; i < (int)(m); i++) {
    auto &seg = ss[i];
    cin >> seg.row >> seg.l >> seg.r;
    --seg.row;
    ls[i] = {seg.l, i};
    rs[i] = {seg.r, i};
    endpoints.push_back(seg.l);
    endpoints.push_back(seg.r);
  }
  sort(ls.begin(), ls.end());
  sort(rs.begin(), rs.end());
  sort(endpoints.begin(), endpoints.end());
  endpoints.erase(unique(endpoints.begin(), endpoints.end()), endpoints.end());
  for (int i = 0, li = 0, ri = 0; i < (int)endpoints.size(); i++) {
    int val = endpoints[i];
    while (li < m && ls[li].first < val) ++li;
    while (li < m && ls[li].first == val) {
      ss[ls[li].second].l = i;
      ++li;
    }
    while (ri < m && rs[ri].first < val) ++ri;
    while (ri < m && rs[ri].first == val) {
      ss[rs[ri].second].r = i;
      ++ri;
    }
  }
  int M = endpoints.size();
  vector<vector<pair<int, int>>> row_segments(n);
  for (const auto &[row, l, r] : ss) {
    row_segments[row].emplace_back(l, r);
  }
  SegTree st{M};
  vector<int> s(n, 0), prev(n, -1);
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      int cur = 1, parent = -1;
      for (auto [l, r] : row_segments[i]) {
        auto [x, y] = st.query(l, r + 1);
        if (x < cur || (x == cur && y != INF)) {
          cur = x;
          parent = (y == INF ? -1 : y);
        }
      }
      s[i] = cur - 1;
      prev[i] = parent;
    }
    for (auto [l, r] : row_segments[i]) {
      st.upd(l, r + 1, {s[i], i});
    }
  }
  int ans = n, ind = -1;
  for (int i = 0; i < n; i++) {
    if (ans > s[i] + n - 1) {
      ans = s[i] + n - 1;
      ind = i;
    }
  }
  cout << ans << "\n";
  if (ans > 0) {
    vector<bool> keep(n);
    while (ind != -1) {
      keep[ind] = 1;
      ind = prev[ind];
    }
    for (int i = 0; i < n; i++) {
      if (keep[i]) continue;
      cout << i + 1 << ' ';
    }
    cout << "\n";
  }
  return 0;
}
