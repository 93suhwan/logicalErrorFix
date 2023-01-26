#include <bits/stdc++.h>
using namespace std;
struct segtree {
  struct node {
    int s1 = 0, s2 = 0;
    void upd(int l, int r, int v1, int v2) {
      s1 += v1;
      s2 += v2;
    }
  };
  node merge(const node &x, const node &y) {
    node ret;
    ret.s1 = x.s1 + y.s1;
    ret.s2 = x.s2 + y.s2;
    return ret;
  }
  void build(int l, int r, int rt) {
    if (l == r) {
      return;
    }
    int m = (l + r) / 2;
    build(l, m, rt << 1);
    build(m + 1, r, rt << 1 | 1);
    a[rt] = merge(a[rt << 1], a[rt << 1 | 1]);
  }
  template <typename T>
  void build(int l, int r, int rt, const vector<T> &v) {
    if (l == r) {
      return;
    }
    int m = (l + r) / 2;
    build(l, m, rt << 1, v);
    build(m + 1, r, rt << 1 | 1, v);
    a[rt] = merge(a[rt << 1], a[rt << 1 | 1]);
  }
  segtree(int n) : n(n), a(n << 2) { build(0, n - 1, 1); }
  template <typename T>
  segtree(const vector<T> &v) : n(v.size()), a(v.size() << 2) {
    build(0, n - 1, 1, v);
  }
  int n;
  vector<node> a;
  template <typename... V>
  void update(int L, int R, int l, int r, int rt, const V &...v) {
    if (L <= l && r <= R) {
      a[rt].upd(l, r, v...);
      return;
    }
    int m = (l + r) / 2;
    if (L <= m) update(L, R, l, m, rt << 1, v...);
    if (m < R) update(L, R, m + 1, r, rt << 1 | 1, v...);
    a[rt] = merge(a[rt << 1], a[rt << 1 | 1]);
  }
  template <typename... V>
  void upd(int L, int R, const V &...v) {
    update(L, R, 0, n - 1, 1, v...);
  }
  int query(int l, int r, int rt, int sl, int sr) {
    if (l == r) return max(min(a[rt].s1 + sl, sr), min(sl, a[rt].s2 + sr));
    node ret;
    int m = (l + r) / 2;
    if (sl + a[rt << 1].s1 < sr + a[rt << 1 | 1].s2)
      return query(m + 1, r, rt << 1 | 1, sl + a[rt << 1].s1, sr);
    return query(l, m, rt << 1, sl, sr + a[rt << 1 | 1].s2);
  }
  int query2(int l, int r, int rt, int sl, int sr) {
    if (l == r) return max(min(a[rt].s2 + sl, sr), min(sl, a[rt].s1 + sr));
    node ret;
    int m = (l + r) / 2;
    if (sl + a[rt << 1].s2 < sr + a[rt << 1 | 1].s1)
      return query2(m + 1, r, rt << 1 | 1, sl + a[rt << 1].s2, sr);
    return query2(l, m, rt << 1, sl, sr + a[rt << 1 | 1].s1);
  }
  int qry() { return max(query(0, n - 1, 1, 0, 0), query2(0, n - 1, 1, 0, 0)); }
};
struct node {
  int x, y, c;
  bool operator<(const node &n) const { return x < n.x; }
};
int solve(vector<node> a, int m) {
  int ret = 0, n = a.size();
  for (int tat = 0; tat < 2; ++tat) {
    sort(a.begin(), a.end());
    for (int qwq = 0; qwq < 2; ++qwq) {
      for (int c1 = 1; c1 <= 3; ++c1) {
        int c2 = c1 % 3 + 1, c3 = c2 % 3 + 1;
        segtree st1(m), st2(m);
        for (auto [x, y, z] : a) {
          if (z != c1) {
            st1.upd(y, y, z == c2, z == c3);
            st2.upd(x, x, z == c2, z == c3);
          }
        }
        int cnt1 = 0;
        for (int i = 0, j; i < n; i = j) {
          j = i;
          while (j < n && a[j].x == a[i].x) {
            if (a[j].c == c1) {
              cnt1++;
            } else {
              st1.upd(a[j].y, a[j].y, -(a[j].c == c2), -(a[j].c == c3));
              st2.upd(a[j].x, a[j].x, -(a[j].c == c2), -(a[j].c == c3));
            }
            ++j;
          }
          ret = max(ret, min(cnt1, st1.qry()));
          ret = max(ret, min(cnt1, st2.qry()));
        }
      }
      reverse(a.begin(), a.end());
    }
    for (auto &[l, r, w] : a) {
      swap(l, r);
    }
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<node> a(n);
  vector<int> b;
  for (auto &[x, y, z] : a) {
    cin >> x >> y >> z;
    b.push_back(x);
    b.push_back(y);
  }
  sort(b.begin(), b.end());
  b.resize(unique(b.begin(), b.end()) - b.begin());
  for (auto &[x, y, z] : a) {
    x = lower_bound(b.begin(), b.end(), x) - b.begin();
    y = lower_bound(b.begin(), b.end(), y) - b.begin();
  }
  sort(a.begin(), a.end());
  cout << solve(a, b.size()) * 3 << '\n';
}
