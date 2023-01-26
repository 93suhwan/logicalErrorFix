#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int mod = (ll)1e9 + 7;
const int INF = 1e9 + 1;
const int N = 2e5 + 100;
const double eps = 1e-7;
template <class T>
using V = vector<T>;
template <class T>
using VV = V<V<T>>;
template <class T, size_t SZ>
using AR = array<T, SZ>;
template <class T>
using PR = pair<T, T>;
template <typename XPAX>
bool ckma(XPAX &x, XPAX y) {
  return (x < y ? x = y, 1 : 0);
}
template <typename XPAX>
bool ckmi(XPAX &x, XPAX y) {
  return (x > y ? x = y, 1 : 0);
}
template <class T>
struct SegTree {
  const T ID{-1};
  T cmb(T a, T b) {
    if (a == -1) return b;
    if (b == -1) return a;
    return min(a, b);
  }
  int n;
  V<T> seg;
  void init(int _n) {
    for (n = 1; n < _n;) n *= 2;
    seg.assign(2 * n, ID);
  }
  void pull(int p) { seg[p] = cmb(seg[2 * p], seg[2 * p + 1]); }
  void upd(int p, T val) {
    seg[p += n] = val;
    for (p /= 2; p; p /= 2) pull(p);
  }
  T query(int l, int r) {
    T ra = ID, rb = ID;
    for (l += n, r += n + 1; l < r; l /= 2, r /= 2) {
      if (l & 1) ra = cmb(ra, seg[l++]);
      if (r & 1) rb = cmb(seg[--r], rb);
    }
    return cmb(ra, rb);
  }
};
SegTree<int> S[2];
void solve() {
  int n;
  cin >> n;
  V<AR<int, 4>> A;
  V<int> x(n), y(n);
  for (int i = 0; i < (n); ++i) cin >> x[i];
  for (int i = 0; i < (n); ++i) cin >> y[i];
  for (int i = 0; i < (n); ++i) {
    int a = x[i], b = y[i];
    A.push_back({a, b, i, 0});
    A.push_back({b, a, i, 1});
  }
  V<int> ans(n);
  S[0].init(n);
  S[1].init(n);
  sort((A).begin(), (A).end(),
       [&](AR<int, 4> a, AR<int, 4> b) { return a[0] > b[0]; });
  for (auto &[a, b, i, t] : A) {
    if (t) swap(a, b);
    if (S[0].query(0, n - 1) <= a) {
      ans[i] = 1;
    }
    if (S[1].query(0, n - 1) <= b) {
      ans[i] = 1;
    }
    if (ans[i]) {
      S[0].upd(i, a);
      S[1].upd(i, b);
    }
  }
  for (int i = 0; i < (n); ++i) cout << ans[i];
  cout << '\n';
}
void test_case() {
  int t;
  cin >> t;
  for (int p = 0; p < (t); ++p) {
    solve();
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  test_case();
}
