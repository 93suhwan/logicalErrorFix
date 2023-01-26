#include <bits/stdc++.h>
using namespace std;
const long long INF = 0x3f3f3f3f;
const long long MOD = 998244353;
const long long N = 6e5 + 10;
struct SEG {
  struct Node {
    long long l, r, mx, idx, cg;
  } t[N << 2];
  void build(long long p, long long l, long long r) {
    t[p].l = l, t[p].r = r;
    t[p].mx = 0, t[p].cg = t[p].idx = -1;
    if (l == r) {
      return;
    }
    long long mid = (l + r) >> 1;
    build((p << 1), l, mid);
    build((p << 1 | 1), mid + 1, r);
  }
  void calc(long long p, long long x, long long id) {
    t[p].mx = t[p].cg = x;
    t[p].idx = id;
  }
  void pushdown(long long p) {
    if (t[p].cg != -1) {
      calc((p << 1), t[p].cg, t[p].idx);
      calc((p << 1 | 1), t[p].cg, t[p].idx);
      t[p].cg = -1;
    }
  }
  void pushup(long long p) {
    t[p].mx = max(t[(p << 1)].mx, t[(p << 1 | 1)].mx);
    t[p].idx = (t[(p << 1)].mx >= t[(p << 1 | 1)].mx) ? t[(p << 1)].idx
                                                      : t[(p << 1 | 1)].idx;
  }
  void update(long long p, long long l, long long r, long long x,
              long long id) {
    if (t[p].l > r || t[p].r < l) return;
    if (t[p].l >= l && t[p].r <= r) {
      calc(p, x, id);
      return;
    }
    pushdown(p);
    update((p << 1), l, r, x, id);
    update((p << 1 | 1), l, r, x, id);
    pushup(p);
  }
  pair<long long, long long> query(long long p, long long l, long long r) {
    if (t[p].l > r || t[p].r < l) return make_pair(0, -1);
    if (t[p].l >= l && t[p].r <= r) {
      return make_pair(t[p].mx, t[p].idx);
    }
    pushdown(p);
    pair<long long, long long> L = query((p << 1), l, r),
                               R = query((p << 1 | 1), l, r);
    return (L.first >= R.first) ? L : R;
  }
} seg;
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  vector<long long> hsh, pre(n, -1);
  vector<vector<pair<long long, long long> > > a(n);
  for (long long i = 0; i < m; i++) {
    long long id, l, r;
    cin >> id >> l >> r;
    a[id - 1].push_back({l, r});
    hsh.push_back(l);
    hsh.push_back(r);
  }
  sort(hsh.begin(), hsh.end());
  hsh.resize(unique(hsh.begin(), hsh.end()) - hsh.begin());
  seg.build(1, 0, hsh.size() - 1);
  for (long long i = 0; i < n; i++) {
    long long mx = 0, prt = -1;
    for (auto &j : a[i]) {
      j.first = lower_bound(hsh.begin(), hsh.end(), j.first) - hsh.begin();
      j.second = lower_bound(hsh.begin(), hsh.end(), j.second) - hsh.begin();
      pair<long long, long long> tmp = seg.query(1, j.first, j.second);
      if (tmp.first > mx) {
        mx = tmp.first;
        prt = tmp.second;
      }
    }
    pre[i] = prt;
    for (auto j : a[i]) {
      seg.update(1, j.first, j.second, mx + 1, i);
    }
  }
  cout << n - seg.t[1].mx << '\n';
  vector<long long> vis(n);
  for (long long i = seg.t[1].idx; i >= 0; i = pre[i]) {
    vis[i] = 1;
  }
  for (long long i = 0; i < n; i++) {
    if (!vis[i]) {
      cout << i + 1 << ' ';
    }
  }
  cout << '\n';
  return 0;
}
