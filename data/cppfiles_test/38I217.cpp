#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll MOD = 1e+9 + 7;
template <typename T, typename L = T>
struct segment_tree {
  using F = std::function<T(const T &, const T &)>;
  int n;
  vector<T> t;
  vector<L> lazy;
  T e;
  F f;
  segment_tree() : n(), e(), f() {}
  template <typename U>
  segment_tree(const vector<U> &v, int n, T e, F f)
      : n(n), t(4 * n), lazy(4 * n), e(e), f(f) {
    build(v, 1, 0, n - 1);
  }
  template <typename U>
  void build(const std::vector<U> &v, int i, int l, int r) {
    if (l == r) {
      t[i] = T(v[l]);
      return;
    }
    int mid = (l + r) >> 1;
    build(v, i << 1, l, mid);
    build(v, i << 1 | 1, mid + 1, r);
    t[i] = f(t[i << 1], t[i << 1 | 1]);
  }
  void push(int i, int l, int r) {}
  template <typename U>
  void update(int ql, int qr, const U &val) {
    update_helper(ql, qr, val, 1, 0, n - 1);
  }
  template <typename U>
  void update_helper1(int idx, U &val, int i, int l, int r) {
    if (l == r) {
      t[i] = T(val);
      return;
    }
    int mid = (l + r) >> 1;
    if (idx <= mid)
      update_helper1(idx, val, i << 1, l, mid);
    else
      update_helper1(idx, val, i << 1 | 1, mid + 1, r);
    t[i] = f(t[i << 1], t[i << 1 | 1]);
  }
  template <typename U>
  void update_helper(int ql, int qr, const U &val, int i, int l, int r) {
    if (r < ql || qr < l) return;
    if (ql <= l && r <= qr) {
      return;
    }
    push(i, l, r);
    int mid = (l + r) >> 1;
    update_helper(ql, qr, val, i << 1, l, mid);
    update_helper(ql, qr, val, i << 1 | 1, mid + 1, r);
    t[i] = f(t[i << 1], t[i << 1 | 1]);
  }
  T query(int ql, int qr) { return query_helper(ql, qr, 1, 0, n - 1); }
  T query_helper(int ql, int qr, int i, int l, int r) {
    if (r < ql || qr < l) return e;
    if (ql <= l && r <= qr) return t[i];
    push(i, l, r);
    int mid = (l + r) >> 1;
    T x = query_helper(ql, qr, i << 1, l, mid),
      y = query_helper(ql, qr, i << 1 | 1, mid + 1, r);
    return f(x, y);
  }
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cout << fixed;
  cout << setprecision(10);
  int n, m;
  cin >> n >> m;
  char g[n + 1][m + 1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> g[i][j];
    }
  }
  bool val[n + 1][m + 1];
  memset(val, false, sizeof val);
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == 1 or j == 1) {
        if (g[j][i] == '.') val[j][i] = true;
      } else if (g[j][i] != 'X')
        val[j][i] = (val[j - 1][i]) or (val[j][i - 1]);
    }
  }
  vector<int> v(m + 1, 1);
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= n; i++) {
      if ((g[i][j] == '.' and !val[i][j]) or (g[i][j] == 'X' and val[i][j])) {
        v[j] = 0;
      }
    }
  }
  segment_tree<int> tree(v, (int)v.size(), INT_MAX,
                         [](int a, int b) { return min(a, b); });
  int q;
  cin >> q;
  while (q--) {
    int a, b;
    cin >> a >> b;
    if (a == b) {
      cout << "YES\n";
      continue;
    }
    int val1 = tree.query(a + 1, b);
    if (val1)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
