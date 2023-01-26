#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
struct SegTree {
  struct Node {
    ll x = 0;
    ll prop = 0;
    void apply(int s, int e, ll add) {
      x += add;
      prop += add;
    }
  };
  inline Node combine(const Node& a, const Node& b) {
    Node res;
    res.x = a.x + b.x;
    return res;
  }
  inline void push(int sn, int s, int e) {
    if (tree[sn].prop) {
      int m = (s + e) >> 1, lsn = sn * 2, rsn = sn * 2 + 1;
      tree[lsn].apply(s, m, tree[sn].prop);
      tree[rsn].apply(m + 1, e, tree[sn].prop);
      tree[sn].prop = 0;
    }
  }
  int start, end;
  vector<Node> tree;
  void build(int sn, int s, int e) {
    if (s == e) {
      return;
    }
    int m = (s + e) >> 1, lsn = sn * 2, rsn = sn * 2 + 1;
    build(lsn, s, m);
    build(rsn, m + 1, e);
    tree[sn] = combine(tree[lsn], tree[rsn]);
  }
  template <typename T>
  void build(int sn, int s, int e, const vector<T>& v) {
    if (s == e) {
      tree[sn].x = v[s];
      return;
    }
    int m = (s + e) >> 1, lsn = sn * 2, rsn = sn * 2 + 1;
    build(lsn, s, m, v);
    build(rsn, m + 1, e, v);
    tree[sn] = combine(tree[lsn], tree[rsn]);
  }
  template <typename... T>
  void update(int sn, int s, int e, int qs, int qe, const T&... v) {
    if (qs <= s && e <= qe) {
      tree[sn].apply(s, e, v...);
      return;
    }
    int m = (s + e) >> 1, lsn = sn * 2, rsn = sn * 2 + 1;
    push(sn, s, e);
    if (qs <= m) update(lsn, s, m, qs, qe, v...);
    if (qe > m) update(rsn, m + 1, e, qs, qe, v...);
    tree[sn] = combine(tree[lsn], tree[rsn]);
  }
  Node query(int sn, int s, int e, int qs, int qe) {
    if (qs <= s && e <= qe) return tree[sn];
    int m = (s + e) >> 1, lsn = sn * 2, rsn = sn * 2 + 1;
    push(sn, s, e);
    if (qe <= m) return query(lsn, s, m, qs, qe);
    if (qs > m) return query(rsn, m + 1, e, qs, qe);
    return combine(query(lsn, s, m, qs, qe), query(rsn, m + 1, e, qs, qe));
  }
  void query(int sn, int s, int e, int qs, int qe,
             const function<void(Node&, int, int)>& f) {
    if (qs <= s && e <= qe) return f(tree[sn], s, e);
    int m = (s + e) >> 1, lsn = sn * 2, rsn = sn * 2 + 1;
    push(sn, s, e);
    if (qs <= m) query(lsn, s, m, qs, qe, f);
    if (qe > m) query(rsn, m + 1, e, qs, qe, f);
  }
  SegTree(int n) : SegTree(0, n - 1) {}
  SegTree(int _start, int _end) : start(_start), end(_end) {
    int n = end - start + 1;
    int maxs = n == 1 ? 2 : 1 << (33 - __builtin_clz(n - 1));
    tree.resize(maxs);
    build(1, start, end);
  }
  template <typename T>
  SegTree(const vector<T>& v) {
    int n = v.size();
    int maxs = n == 1 ? 2 : 1 << (33 - __builtin_clz(n - 1));
    tree.resize(maxs);
    start = 0;
    end = n - 1;
    build(1, start, end, v);
  }
  Node query(int qs, int qe) { return query(1, start, end, qs, qe); }
  Node query(int p) { return query(1, start, end, p, p); }
  void query(int qs, int qe, const function<void(Node&, int, int)>& f) {
    if (qs > qe) return;
    query(1, start, end, qs, qe, f);
  }
  template <typename... T>
  void update(int qs, int qe, const T&... v) {
    update(1, start, end, qs, qe, v...);
  }
  int findFirst(int sn, int s, int e, int qs, int qe,
                const function<bool(Node&, int, int)>& f) {
    if (qs <= s && e <= qe) {
      if (!f(tree[sn], s, e)) return -1;
      if (s == e) return s;
    }
    int m = (s + e) >> 1, lsn = sn * 2, rsn = sn * 2 + 1, ret = -1;
    push(sn, s, e);
    if (qs <= m) ret = findFirst(lsn, s, m, qs, qe, f);
    if (qe > m && ret == -1) ret = findFirst(rsn, m + 1, e, qs, qe, f);
    return ret;
  }
  int findFirst(int qs, int qe, const function<bool(Node&, int, int)>& f) {
    return findFirst(1, start, end, qs, qe, f);
  }
  int findLast(int sn, int s, int e, int qs, int qe,
               const function<bool(Node&, int, int)>& f) {
    if (qs <= s && e <= qe) {
      if (!f(tree[sn], s, e)) return -1;
      if (s == e) return s;
    }
    int m = (s + e) >> 1, lsn = sn * 2, rsn = sn * 2 + 1, ret = -1;
    push(sn, s, e);
    if (qe > m) ret = findLast(rsn, m + 1, e, qs, qe, f);
    if (qs <= m && ret == -1) ret = findLast(lsn, s, m, qs, qe, f);
    return ret;
  }
  int findLast(int qs, int qe, const function<bool(Node&, int, int)>& f) {
    return findLast(1, start, end, qs, qe, f);
  }
};
template <typename T>
struct Fenwick {
  int n;
  vector<T> bit;
  Fenwick(int _n) : n(_n), bit(n + 1) {}
  void update(int p, T v) {
    for (++p; p <= n; p += p & -p) bit[p] += v;
  }
  T query(int p) {
    T ret{};
    for (++p; p > 0; p -= p & -p) ret += bit[p];
    return ret;
  }
};
int main() {
  int n;
  scanf("%d", &n);
  vector<int> A(n);
  const int MAX = 300000;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &A[i]);
  }
  Fenwick<int> fcnt(MAX + 1);
  Fenwick<ll> fsum(MAX + 1);
  ll curSum = 0;
  vector<ll> ans(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= MAX; j += A[i]) {
      int k = min(MAX, j + A[i] - 1);
      int cnt = fcnt.query(k) - fcnt.query(j - 1);
      ll sum = fsum.query(k) - fsum.query(j - 1);
      ll add = sum - (ll)cnt * j;
      curSum += add;
    }
    fcnt.update(A[i], 1);
    fsum.update(A[i], A[i]);
    42;
    ans[i] = curSum;
  }
  SegTree st(MAX + 1);
  for (int i = n - 1; i >= 0; --i) {
    for (int j = 0; j <= MAX; j += A[i]) {
      int k = min(MAX, j + A[i] - 1);
      st.update(j, k, j);
    }
    st.update(A[i], A[i], -st.query(A[i]).x);
  }
  curSum = 0;
  for (int i = 0; i < n; ++i) {
    curSum += (ll)A[i] * i;
    curSum -= st.query(A[i]).x;
    ans[i] += curSum;
    printf("%lld ", ans[i]);
  }
}
