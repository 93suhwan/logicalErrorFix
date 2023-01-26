#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;
int power(int a, int b) {
  int res = 1;
  a = a % MOD;
  while (b > 0) {
    if (b & 1) {
      res = (res * a) % MOD;
      b--;
    }
    a = (a * a) % MOD;
    b >>= 1;
  }
  return res;
}
int fermat_inv(int y) { return power(y, MOD - 2); }
int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }
int min(int a, int b) { return (a > b) ? b : a; }
int max(int a, int b) { return (a > b) ? a : b; }
struct node {
  bitset<515> x;
  node() {
    x.reset();
    x[0] = 1;
  }
  node operator+(const node& other) {
    node sum = node();
    sum.x = (x | other.x);
    return sum;
  }
};
struct SegTree {
  vector<node> t;
  int n;
  SegTree(int n) {
    this->n = n;
    t.assign(4 * n, node());
  }
  node sum(int v, int tl, int tr, int l, int r) {
    if (l > r) return node();
    if (l == tl && r == tr) return t[v];
    int tm = (tl + tr) / 2;
    return sum(v * 2, tl, tm, l, min(r, tm)) +
           sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
  }
  bitset<515> sum(int l, int r) {
    l++, r++;
    return sum(1, 1, n, l, r).x;
  }
  void update(int v, int tl, int tr, int pos, bitset<515> new_val) {
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
  void update(int idx, bitset<515> a) {
    idx++;
    update(1, 1, n, idx, a);
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int te = 1;
  while (te--) {
    int n;
    cin >> n;
    int a[n];
    for (int& i : a) cin >> i;
    vector<int> ans;
    SegTree ST(515 + 5);
    for (int i = 0; i < n; i++) {
      bitset<515> curr, pre;
      pre = ST.sum(0, a[i] - 1);
      curr = pre;
      for (int j = 0; j < 515; j++) {
        if (pre[j]) curr[j ^ a[i]] = 1;
      }
      ST.update(a[i], curr);
    }
    for (int i = 0; i <= 512; i++) {
      if (ST.sum(0, 515)[i]) ans.push_back(i);
    }
    sort((ans).begin(), (ans).end());
    cout << ans.size() << '\n';
    for (int i : ans) cout << i << ' ';
    cout << '\n';
  }
}
