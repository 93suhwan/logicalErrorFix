#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
const double PI = acos(-1);
struct item {
  int len, L, R;
};
struct segtree {
  int sz;
  vector<item> values;
  void init(int n) {
    sz = 1;
    while (sz < n) sz *= 2;
    values.resize(2 * sz);
  }
  item NEUTRAL_ELEMENT = {0, 0, 0};
  item merge(item a, item b) {
    if (a.len == 0) return b;
    if (b.len == 0) return a;
    if (a.R == b.L) {
      if (a.len == b.len) return {0, 0, 0};
      if (a.len > b.len) {
        int l = a.L;
        int r;
        int rem = a.len - b.len;
        if ((rem - 1) % 2 == 0)
          r = a.L;
        else
          r = !a.L;
        return {rem, l, r};
      } else {
        int r = b.R;
        int l;
        int rem = b.len - a.len;
        if (rem % 2 == 0) {
          l = !b.R;
        } else
          l = b.R;
        return {rem, l, r};
      }
    } else {
      return {a.len + b.len, a.L, b.R};
    }
  }
  item single(int v) { return {1, v, v}; }
  void build(vector<int> &a, int x, int lx, int rx) {
    if (rx - lx == 1) {
      if (lx < (int)a.size()) {
        values[x] = single(a[lx]);
      }
      return;
    }
    int m = (lx + rx) / 2;
    build(a, 2 * x + 1, lx, m);
    build(a, 2 * x + 2, m, rx);
    values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
  }
  void build(vector<int> &a) { build(a, 0, 0, sz); }
  item calc(int l, int r, int x, int lx, int rx) {
    if (l >= rx || lx >= r) return NEUTRAL_ELEMENT;
    if (lx >= l && rx <= r) return values[x];
    int m = (lx + rx) / 2;
    item s1 = calc(l, r, 2 * x + 1, lx, m);
    item s2 = calc(l, r, 2 * x + 2, m, rx);
    return merge(s1, s2);
  }
  item calc(int l, int r) { return calc(l, r, 0, 0, sz); }
};
void solve() {
  int n, q;
  cin >> n >> q;
  string s;
  cin >> s;
  vector<int> a;
  for (char c : s) {
    if (c == '+')
      a.push_back(1);
    else
      a.push_back(0);
  }
  segtree st;
  st.init(a.size());
  st.build(a);
  while (q--) {
    int l, r;
    cin >> l >> r;
    int len = st.calc(l - 1, r).len;
    if (len == 0) {
      cout << "0\n";
      continue;
    }
    if (len % 2 == 0)
      cout << 2 << "\n";
    else
      cout << 1 << "\n";
  }
}
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
