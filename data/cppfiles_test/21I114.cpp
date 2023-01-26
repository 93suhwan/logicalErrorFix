#include <bits/stdc++.h>
using namespace std;
long long int power(long long int a, long long int b) {
  long long int res = 1;
  a = a % 998244353;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % 998244353;
      b--;
    }
    a = (a * a) % 998244353;
    b >>= 1;
  }
  return res;
}
long long int fermat_inv(long long int y) { return power(y, 998244353 - 2); }
long long int gcd(long long int a, long long int b) {
  return (b == 0) ? a : gcd(b, a % b);
}
long long int min(long long int a, long long int b) { return (a > b) ? b : a; }
long long int max(long long int a, long long int b) { return (a > b) ? a : b; }
struct node {
  long long int x;
  node() { x = 0; }
  node operator+(const node& other) {
    node sum = node();
    sum.x = (x + other.x) % 998244353;
    return sum;
  }
};
struct SegTree {
  vector<node> t;
  long long int n;
  SegTree(long long int n) {
    this->n = n;
    t.assign(4 * n, node());
  }
  SegTree(vector<long long int>& a) : SegTree(a.size()) { build(a, 1, 1, n); }
  void build(vector<long long int>& a, int v, int tl, int tr) {
    if (tl == tr)
      t[v].x = a[tl - 1];
    else {
      int tm = (tl + tr) / 2;
      build(a, v * 2, tl, tm);
      build(a, v * 2 + 1, tm + 1, tr);
      t[v] = t[v * 2] + t[v * 2 + 1];
    }
  }
  node sum(int v, int tl, int tr, int l, int r) {
    if (l > r) return node();
    if (l == tl && r == tr) return t[v];
    int tm = (tl + tr) / 2;
    return sum(v * 2, tl, tm, l, min(r, tm)) +
           sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
  }
  long long int sum(int l, int r) { return sum(1, 1, n, l, r).x; }
  void update(int v, int tl, int tr, int pos, long long int new_val) {
    if (tl == tr)
      t[v].x = new_val;
    else {
      int tm = (tl + tr) / 2;
      if (pos <= tm)
        update(2 * v, tl, tm, pos, new_val);
      else
        update(2 * v + 1, tm + 1, tr, pos, new_val);
      t[v] = t[2 * v] + t[2 * v + 1];
    }
  }
  void update(int idx, long long int a) { update(1, 1, n, idx, a); }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int te = 1;
  while (te--) {
    long long int n;
    cin >> n;
    long long int x[n], y[n], f[n];
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> f[i];
    long long int ans = x[n - 1] + 1;
    map<long long int, long long int> m;
    for (int i = 0; i < n; i++) m[x[i]]++, m[y[i]]++;
    int c = 0;
    for (auto i : m) m[i.first] = ++c;
    SegTree ST(c + 5);
    for (int i = 0; i < n; i++) {
      long long int s = ST.sum(m[y[i]], m[x[i]]);
      (s += x[i] - y[i]) %= 998244353;
      ST.update(m[x[i]], s);
      if (f[i]) (ans += s) %= 998244353;
    }
    cout << ans << '\n';
  }
}
