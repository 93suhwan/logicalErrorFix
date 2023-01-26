#include <bits/stdc++.h>
using namespace std;
template <typename T, typename L>
struct lazyseg {
  int N = 1;
  vector<T> seg;
  vector<L> lazy;
  vector<bool> flag;
  void init(int n) {
    while (N < n) N *= 2;
    seg.resize(2 * N, inil);
    lazy.resize(2 * N, lazynil);
    flag.resize(2 * N, 0);
  }
  void init(vector<T> &v, int offset = 0) {
    int n = v.size();
    while (N < n + offset) N *= 2;
    seg.resize(2 * N, inil);
    lazy.resize(2 * N, lazynil);
    flag.resize(2 * N, 0);
    for (int i = 0; i < n; i++) seg[N + i + offset] = v[i];
    for (int i = N - 1; i; i--) seg[i] = segjoin(seg[2 * i], seg[2 * i + 1]);
  }
  int ql, qr;
  L val;
  T nil, inil;
  L lazynil;
  virtual T segjoin(T a, T b) = 0;
  virtual void lazyjoin(L &a, L &b) = 0;
  virtual T lazymerge(T &a, L &b, int d) = 0;
  void push(int k, int d) {
    if (flag[k]) {
      seg[k] = lazymerge(seg[k], lazy[k], d);
      if (k < N) {
        lazyjoin(lazy[2 * k], lazy[k]);
        lazyjoin(lazy[2 * k + 1], lazy[k]);
        flag[2 * k] = flag[2 * k + 1] = 1;
      }
      flag[k] = 0;
      lazy[k] = lazynil;
    }
  }
  T ioper(int l, int r, int k) {
    push(k, r - l);
    if (qr <= l || ql >= r) return seg[k];
    if (ql <= l && qr >= r) {
      flag[k] = 1;
      lazyjoin(lazy[k], val);
      return lazymerge(seg[k], lazy[k], r - l);
    }
    int m = (l + r) / 2;
    seg[k] = segjoin(ioper(l, m, 2 * k), ioper(m, r, 2 * k + 1));
    return seg[k];
  }
  T iqer(int l, int r, int k) {
    push(k, r - l);
    if (qr <= l || ql >= r) return nil;
    if (ql <= l && qr >= r) return seg[k];
    int m = (l + r) / 2;
    return segjoin(iqer(l, m, 2 * k), iqer(m, r, 2 * k + 1));
  }
  T qer(int l, int r) {
    if (l > r) return nil;
    ql = l;
    qr = r + 1;
    return iqer(0, N, 1);
  }
  void oper(int l, int r, L o) {
    if (l <= r) {
      ql = l;
      qr = r + 1;
      val = o;
      ioper(0, N, 1);
    }
  }
};
const int inf = 1e9;
template <typename T, typename L>
struct segmin : public lazyseg<T, L> {
  segmin() {
    this->nil = {inf, inf};
    this->inil = {inf, inf};
    this->lazynil = {inf, inf};
  }
  T segjoin(T a, T b) { return min(a, b); }
  void lazyjoin(L &a, L &b) { a = min(a, b); }
  T lazymerge(T &a, L &b, int d) { return min(a, b); }
};
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int &i : a) cin >> i;
  for (int &i : b) cin >> i;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  vector<vector<int> > g(n);
  for (int i = 0; i < n; i++) g[i - b[i]].push_back(i);
  vector<int> pp(n + 1, inf);
  vector<array<int, 2> > pr(n + 1, {inf, inf});
  segmin<array<int, 2>, array<int, 2> > dp;
  dp.init(n + 1);
  dp.oper(0, 0, {0, 0});
  for (int i = 0; i < n; i++) {
    for (int j : g[i]) {
      auto mm = dp.qer(j, j);
      if (mm < pr[i]) {
        pp[i] = j;
        pr[i] = mm;
      }
    }
    if (pr[i][0] != inf && a[i]) {
      dp.oper(i + 1, i + a[i], {pr[i][0] + 1, i});
    }
  }
  pr[n] = dp.qer(n, n);
  if (pr[n][0] != inf) {
    vector<int> ans(1, 0);
    int j = pr[n][1];
    while (j) {
      ans.push_back(n - pp[j]);
      j = pr[j][1];
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int i : ans) cout << i << ' ';
    cout << '\n';
  } else {
    cout << "-1\n";
  }
  return 0;
}
