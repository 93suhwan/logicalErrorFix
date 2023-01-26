#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
void fileio(const string &s) {
  freopen((s + ".in").c_str(), "r", stdin);
  freopen((s + ".out").c_str(), "w", stdout);
}
const long long INF = 4e18;
inline long long read() {
  long long x = 0;
  bool flag = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') flag = 0;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return (flag ? x : ~(x - 1));
}
long long T, n, m, cnt, root, tot, a[1000001], b[1000001], L[2000001],
    R[2000001], tag[2000001], t1[2000001];
array<long long, 2> t[2000001], aa[1000001], c[2000001];
void push_up(long long x) {
  if (t[L[x]][0] < t[R[x]][0])
    t[x] = t[L[x]];
  else
    t[x] = t[R[x]];
}
void build(long long &x, long long l, long long r) {
  if (!x) x = ++cnt;
  if (l == r) {
    t[x] = {l, l};
    return;
  }
  long long mid = (l + r) >> 1;
  build(L[x], l, mid);
  build(R[x], mid + 1, r);
  push_up(x);
}
void push_down(long long x) {
  long long k = tag[x];
  tag[x] = 0;
  t[L[x]][0] += k;
  t[R[x]][0] += k;
  tag[L[x]] += k;
  tag[R[x]] += k;
}
void modify(long long x, long long l, long long r, long long ll, long long rr,
            long long k) {
  if (l >= ll && r <= rr) {
    t[x][0] += k;
    tag[x] += k;
    return;
  }
  push_down(x);
  long long mid = (l + r) >> 1;
  if (ll <= mid) modify(L[x], l, mid, ll, rr, k);
  if (rr > mid) modify(R[x], mid + 1, r, ll, rr, k);
  push_up(x);
}
array<long long, 2> query(long long x, long long l, long long r, long long ll,
                          long long rr) {
  if (l >= ll && r <= rr) return t[x];
  push_down(x);
  long long mid = (l + r) >> 1;
  array<long long, 2> res = {INF, 0}, re;
  if (ll <= mid) {
    re = query(L[x], l, mid, ll, rr);
    if (re[0] < res[0]) res = re;
  }
  if (rr > mid) {
    re = query(R[x], mid + 1, r, ll, rr);
    if (re[0] < res[0]) res = re;
  }
  return res;
}
long long lowbit(long long x) { return x & -x; }
void add(long long x) {
  for (; x <= tot; x += lowbit(x)) t1[x]++;
}
long long ask(long long x) {
  long long res = 0;
  for (; x; x -= lowbit(x)) res += t1[x];
  return res;
}
void solve() {
  n = read();
  m = read();
  for (long long i = 1; i <= n; i++) a[i] = read();
  for (long long i = 1; i <= m; i++) b[i] = read();
  sort(b + 1, b + 1 + m);
  for (long long i = 1; i <= n; i++) aa[i] = {a[i], i};
  sort(aa + 1, aa + 1 + n);
  fill(L + 1, L + 1 + 2 * n, 0);
  fill(R + 1, R + 1 + 2 * n, 0);
  fill(tag + 1, tag + 1 + 2 * n, 0);
  root = tot = cnt = 0;
  build(root, 1, n);
  for (long long i = 1, l = 1, lst = 0; i <= m; i++) {
    while (l <= n && aa[l][0] <= b[i]) {
      modify(root, 1, n, aa[l][1], n, -2);
      l++;
    }
    array<long long, 2> q = query(root, 1, n, 1, n);
    if (q[0] > 0) q = {0, 0};
    for (long long j = lst + 1; j <= q[1]; j++) c[++tot][0] = a[j];
    c[++tot][0] = b[i];
    lst = q[1];
  }
  for (long long i = 1; i <= tot; i++) c[i][1] = i;
  sort(c + 1, c + 1 + tot);
  long long ans = 0;
  fill(t1 + 1, t1 + 1 + tot, 0);
  for (long long i = tot; i >= 1; i--) {
    ans += ask(c[i][1] - 1);
    add(c[i][1]);
  }
  cout << ans << endl;
}
signed main() {
  T = read();
  while (T--) solve();
  return 0;
}
