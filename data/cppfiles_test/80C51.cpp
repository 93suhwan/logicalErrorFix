#include <bits/stdc++.h>
using namespace std;
template <class T>
using min_heap = priority_queue<T, vector<T>, greater<T> >;
struct LazySegTree {
  long long MX;
  vector<long long> st, lz;
  LazySegTree(long long M) {
    MX = M;
    st.resize(4 * MX + 5);
    lz.resize(4 * MX + 5);
  }
  void build(long long l, long long r, long long pos) {
    if (l == r) {
      st[pos] = l;
      return;
    }
    long long lc = pos << 1, rc = lc ^ 1, mid = (l + r) >> 1;
    build(l, mid, lc);
    build(mid + 1, r, rc);
    st[pos] = l;
  }
  void adjust(long long l, long long r, long long pos) {
    long long lc = pos << 1, rc = lc ^ 1;
    if (lz[pos]) {
      st[pos] += lz[pos];
      if (l != r) {
        lz[lc] += lz[pos];
        lz[rc] += lz[pos];
      }
      lz[pos] = 0;
    }
  }
  void _upd(long long ql, long long qr, long long del, long long l, long long r,
            long long pos) {
    adjust(l, r, pos);
    long long lc = pos << 1, rc = lc ^ 1;
    if (qr < l || ql > r)
      return;
    else if (ql <= l && qr >= r) {
      st[pos] += del;
      if (l != r) {
        lz[lc] += del;
        lz[rc] += del;
      }
      return;
    }
    long long mid = (l + r) >> 1;
    _upd(ql, qr, del, l, mid, lc);
    _upd(ql, qr, del, mid + 1, r, rc);
    st[pos] = min(st[lc], st[rc]);
  }
  long long _qry(long long ql, long long qr, long long l, long long r,
                 long long pos) {
    adjust(l, r, pos);
    long long lc = pos << 1, rc = lc ^ 1;
    if (qr < l || ql > r)
      return 0;
    else if (ql <= l && qr >= r)
      return st[pos];
    long long mid = (l + r) >> 1;
    return min(_qry(ql, qr, l, mid, lc), _qry(ql, qr, mid + 1, r, rc));
  }
  long long _search(long long rem, long long l, long long r, long long pos) {
    adjust(l, r, pos);
    long long lc = pos << 1, rc = lc ^ 1;
    if (l == r) return l;
    long long mid = (l + r) >> 1;
    adjust(l, mid, lc);
    adjust(mid + 1, r, rc);
    if (st[lc] >= rem) return _search(rem, l, mid, lc);
    return _search(rem - st[lc], mid + 1, r, rc);
  }
  void upd(long long ql, long long qr, long long del) {
    _upd(ql, qr, del, 1, MX, 1);
  }
  long long qry(long long ql, long long qr) { return _qry(ql, qr, 1, MX, 1); }
  long long search(long long rem) { return _search(rem, 1, MX, 1); }
};
struct fenwick_tree {
  long long n;
  vector<long long> BIT;
  fenwick_tree(long long nn) {
    n = nn;
    BIT.resize(n + 1, 0LL);
  }
  void upd(long long idx, long long delta) {
    while (idx <= n) {
      BIT[idx] += delta;
      idx += (idx & (-idx));
    }
  }
  long long pref(long long idx) {
    long long res = 0;
    while (idx > 0) {
      res += BIT[idx];
      idx -= (idx & (-idx));
    }
    return res;
  }
  long long suff(long long idx) {
    long long res = pref(n);
    if (idx > 0) res -= pref(idx - 1);
    return res;
  }
};
const long long N = 1e6 + 6;
long long n, m, a[N], b[N];
vector<long long> v1[2 * N];
long long v2[2 * N];
long long calc_inv() {
  fenwick_tree f1(n + m + 1);
  long long res = 0;
  for (long long i = 1; i < n + 1; i++) {
    if (a[i] != n + m + 1) res += f1.suff(a[i] + 1);
    f1.upd(a[i], 1);
  }
  return res;
}
void clr() {
  for (long long i = 1; i < n + 1; i++) v1[a[i]].clear();
  for (long long i = 1; i < m + 1; i++) v2[b[i]] = 0;
}
void func() {
  cin >> n >> m;
  for (long long i = 1; i < n + 1; i++) cin >> a[i];
  for (long long i = 1; i < m + 1; i++) cin >> b[i];
  vector<long long> vec;
  for (long long i = 1; i < n + 1; i++) vec.push_back(a[i]);
  for (long long i = 1; i < m + 1; i++) vec.push_back(b[i]);
  sort(vec.begin(), vec.end());
  vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
  for (long long i = 1; i < n + 1; i++) {
    a[i] = lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin() + 1;
    v1[a[i]].push_back(i);
  }
  for (long long i = 1; i < m + 1; i++) {
    b[i] = lower_bound(vec.begin(), vec.end(), b[i]) - vec.begin() + 1;
    v2[b[i]]++;
  }
  LazySegTree T(n);
  T.build(1, n, 1);
  long long smaller = 0, ans = 0;
  for (long long i = 1; i < n + m + 1; i++) {
    if (v2[i] == 0) {
      for (auto j : v1[i]) T.upd(j, n, -2);
    } else {
      for (auto j : v1[i]) T.upd(j, n, -1);
      long long res = min(0LL, T.qry(1, n));
      ans += ((res + smaller) * v2[i]);
      for (auto j : v1[i]) T.upd(j, n, -1);
    }
    smaller += (long long)v1[i].size();
  }
  ans += calc_inv();
  cout << ans << "\n";
}
int main() {
  {
    ios ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
  }
  cout << fixed << setprecision(10);
  long long ntc = 1;
  cin >> ntc;
  for (long long i = 1; i < ntc + 1; i++) {
    func();
    clr();
  }
  return 0;
}
