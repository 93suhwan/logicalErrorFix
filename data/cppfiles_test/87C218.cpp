#include <bits/stdc++.h>
using namespace std;
template <typename T, typename U>
bool ckmin(T &a, const U &b) {
  return b < a ? a = b, true : false;
}
template <typename T, typename U>
bool ckmax(T &a, const U &b) {
  return b > a ? a = b, true : false;
}
template <typename T>
struct SegmentTree {
  int SZ;
  T id;
  vector<T> t;
  SegmentTree(T x, int sz) : id(x), SZ(sz) { t.assign((SZ << 2) + 5, id); }
  SegmentTree(vector<T> &a, T x, int sz) {
    id = x;
    SZ = sz;
    t.assign((SZ << 2) + 5, id);
    build(1, 0, SZ - 1, a);
  }
  T cmb(T x, T y) { return x + y; }
  void build(int v, int tl, int tr, vector<T> &a) {
    if (tl == tr)
      t[v] = a[tl];
    else {
      int tm = tl + (tr - tl) / 2;
      build(v << 1, tl, tm, a);
      build((v << 1) | 1, tm + 1, tr, a);
      t[v] = cmb(t[v << 1], t[(v << 1) | 1]);
    }
  }
  T qry(int l, int r) { return qry(1, 0, SZ - 1, l, r); }
  T qry(int v, int tl, int tr, int l, int r) {
    if (l > r) return id;
    if (tl == l && tr == r) return t[v];
    int tm = tl + (tr - tl) / 2;
    return cmb(qry(v << 1, tl, tm, l, min(r, tm)),
               qry((v << 1) | 1, tm + 1, tr, max(l, tm + 1), r));
  }
  void upd(int u, T x) { upd(1, 0, SZ - 1, u, x); }
  void upd(int v, int tl, int tr, int u, T x) {
    if (tl == tr)
      t[v] = x;
    else {
      int tm = tl + (tr - tl) / 2;
      if (u > tm)
        upd((v << 1) | 1, tm + 1, tr, u, x);
      else
        upd(v << 1, tl, tm, u, x);
      t[v] = cmb(t[v << 1], t[(v << 1) | 1]);
    }
  }
  void chng(int u, T x) { chng(1, 0, SZ - 1, u, x); }
  void chng(int v, int tl, int tr, int u, T x) {
    if (tl == tr)
      t[v] = cmb(t[v], x);
    else {
      int tm = tl + (tr - tl) / 2;
      if (u > tm)
        chng((v << 1) | 1, tm + 1, tr, u, x);
      else
        chng(v << 1, tl, tm, u, x);
      t[v] = cmb(t[v << 1], t[(v << 1) | 1]);
    }
  }
};
int tt;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n >> m;
    vector<array<int, 2>> v(n * m, array<int, 2>());
    vector<SegmentTree<int>> trees(n, SegmentTree<int>(0, m + 1));
    for (int i = 0; i < n * m; ++i) {
      cin >> v[i][0];
      v[i][1] = -i;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n * m; ++i) {
      v[i][0] = i;
      swap(v[i][0], v[i][1]);
      v[i][0] *= -1;
    }
    sort(v.begin(), v.end());
    long long res = 0;
    for (int i = 0; i < n * m; ++i) {
      int pos = v[i][1];
      res += trees[pos / m].qry(0, pos % m);
      trees[pos / m].upd(pos % m, 1);
    }
    cout << res << "\n";
  }
  return 0;
}
