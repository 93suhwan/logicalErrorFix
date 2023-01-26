#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
struct node {
  long long v = 0;
  node() {}
  node(long long val) { v = val; }
  void merge(const node &l, const node &r) { v = l.v + r.v; }
};
template <typename node>
struct segtree {
  int len;
  vector<node> t;
  node identity_element;
  segtree(int l) {
    len = l;
    t.resize(4 * len);
    identity_element = node();
  }
  node query(const int32_t &v, const int32_t &tl, const int32_t &tr,
             const int32_t &l, const int32_t &r) {
    if (l > tr || r < tl) return identity_element;
    if (l <= tl && tr <= r) return t[v];
    int32_t tm = (tl + tr) >> 1;
    node a = query(v << 1, tl, tm, l, r),
         b = query(v << 1 | 1, tm + 1, tr, l, r), ans;
    ans.merge(a, b);
    return ans;
  }
  void rupd(const int32_t &v, const int32_t &tl, const int32_t &tr,
            const int32_t &l, const int32_t &r, const long long &upd) {
    if (l > tr || r < tl) return;
    if (l <= tl && tr <= r) {
      t[v].v += upd;
      return;
    }
    int32_t tm = (tl + tr) >> 1;
    rupd(v << 1, tl, tm, l, r, upd);
    rupd(v << 1 | 1, tm + 1, tr, l, r, upd);
    t[v].merge(t[v << 1], t[v << 1 | 1]);
  }

 public:
  node query(const int32_t &l, const int32_t &r) {
    return query(1, 0, len - 1, l, r);
  }
  void rupd(const int32_t &l, const int32_t &r, const long long &upd) {
    rupd(1, 0, len - 1, l, r, upd);
  }
};
void solve() {
  int n, x, M = 2 * N;
  long long res = 0;
  cin >> n;
  segtree<node> cnt(N), b(N), pre(N);
  for (int i = 0; i < n; i++) {
    cin >> x;
    res += 1ll * i * x - b.query(0, x).v;
    for (int j = x; j < N; j += x) {
      int prev = j - x;
      long long sum = pre.query(prev, j - 1).v, e = cnt.query(prev, j - 1).v;
      res += sum - e * prev;
      b.rupd(j, j, x);
    }
    cnt.rupd(x, x, 1);
    pre.rupd(x, x, x);
    cout << res << " ";
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  solve();
  return 0;
}
