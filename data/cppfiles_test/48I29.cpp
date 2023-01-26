#include <bits/stdc++.h>
#pragma optimize("unroll-loops")
using namespace std;
const long long N = 1 << 18;
const long long M = 1e10 + 7;
struct node {
  long long sum, pref, suff, ans;
};
class segTree {
 public:
  vector<node> t;
  segTree(int n) {
    int res = 1;
    while (res <= n) res *= 2;
    t.resize(2 * res);
  }
  node combine(node l, node r) {
    node res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(r.suff, r.sum + l.suff);
    res.ans = max(max(l.ans, r.ans), l.suff + r.pref);
    return res;
  }
  node make_data(long long val) {
    node res;
    res.sum = val;
    res.pref = res.suff = res.ans = max(0ll, val);
    return res;
  }
  void build(long long a[], long long v, long long tl, long long tr) {
    if (tl == tr) {
      t[v] = make_data(a[tl]);
    } else {
      long long tm = (tl + tr) / 2;
      build(a, v * 2, tl, tm);
      build(a, v * 2 + 1, tm + 1, tr);
      t[v] = combine(t[v * 2], t[v * 2 + 1]);
    }
  }
  node query(long long v, long long tl, long long tr, long long l,
             long long r) {
    if (l > r) return make_data(0);
    if (l == tl && r == tr) return t[v];
    long long tm = (tl + tr) / 2;
    return combine(query(v * 2, tl, tm, l, min(r, tm)),
                   query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
  }
};
int main() {
  long long n, kyu;
  cin >> n >> kyu;
  long long a[n];
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long tmp, pre[n];
  for (long long i = 0; i < n; i++) {
    cin >> tmp;
    a[i] = tmp - a[i];
    pre[i] = a[i];
    if (i > 0) pre[i] += pre[i - 1];
  }
  long long st[n][17];
  for (long long i = 0; i < n; i++) st[i][0] = pre[i];
  for (long long j = 1; j < 17; j++)
    for (long long i = 0; i < n; i++)
      if (i + (1 << j - 1) < n)
        st[i][j] = min(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
      else
        st[i][j] = st[i][j - 1];
  long long b[n];
  for (long long i = 0; i < n; i++) b[i] = a[i];
  for (long long i = 0; i < n; i++)
    if (a[i] < 0)
      a[i] = -M, b[i] = -b[i];
    else
      b[i] = -M;
  segTree A(n), B(n);
  A.build(a, 1, 0, n - 1);
  B.build(b, 1, 0, n - 1);
  while (kyu--) {
    long long l, r;
    cin >> l >> r;
    --l, --r;
    long long df = r - l + 1;
    df = log2(df);
    long long mn = min(st[l][df], st[r - (1 << df) + 1][df]);
    long long last = 0;
    if (l > 0) last = pre[l - 1];
    if (mn < last || pre[r] != last) {
      cout << -1 << '\n';
      continue;
    }
    cout << max(A.query(1, 0, n - 1, l, r).ans, B.query(1, 0, n - 1, l, r).ans)
         << '\n';
  }
}
