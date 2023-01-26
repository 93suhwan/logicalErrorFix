#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
template <typename T>
struct segtree {
  int N = 1;
  vector<T> seg;
  void init(int n) {
    while (N < n) N *= 2;
    seg.resize(2 * N, inil);
  }
  void init(vector<T> &v, int offset = 0) {
    int n = v.size();
    while (N < n + offset) N *= 2;
    seg.resize(2 * N, inil);
    for (int i = 0; i < n; i++) seg[N + i + offset] = v[i];
    for (int i = N - 1; i; i--) seg[i] = join(seg[2 * i], seg[2 * i + 1]);
  }
  T inil;
  T nil;
  virtual T join(T a, T b) = 0;
  virtual T drop(T a, T b) = 0;
  T qer(int l, int r) {
    l += N;
    r += N;
    T s = nil;
    while (l <= r) {
      if (l & 1) s = join(s, seg[l++]);
      if (~r & 1) s = join(s, seg[r--]);
      l /= 2;
      r /= 2;
    }
    return s;
  }
  void oper(int i, T o) {
    i += N;
    seg[i] = drop(seg[i], o);
    for (i /= 2; i; i /= 2) seg[i] = join(seg[2 * i], seg[2 * i + 1]);
  }
};
template <typename T>
struct segmin : public segtree<T> {
  segmin() {
    this->nil = {inf, inf};
    this->inil = {inf, inf};
  }
  T join(T a, T b) { return min(a, b); }
  T drop(T a, T b) { return min(a, b); }
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
  segmin<array<int, 2> > dp;
  dp.init(n + 1);
  dp.oper(0, {0, 0});
  for (int i = 0; i < n; i++) {
    for (int j : g[i]) {
      auto mm = dp.qer(j, n);
      if (mm < pr[i]) {
        pp[i] = j;
        pr[i] = mm;
      }
    }
    if (pr[i][0] != inf) {
      dp.oper(i + a[i], {pr[i][0] + 1, i});
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
