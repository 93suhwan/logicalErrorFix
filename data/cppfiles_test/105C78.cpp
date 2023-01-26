#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') f = ch == '-' ? -1 : 1, ch = getchar();
  while (ch >= '0' && ch <= '9') x = x * 10 + ch - 48, ch = getchar();
  return x * f;
}
const long long N(2e5 + 10);
long long n, tot;
struct Node {
  long long a, b, m, s, id;
} d[N];
struct Line {
  long long l, r, v, id;
} a[N];
long long x[N];
long long rx[N];
long long ry[N];
inline bool cmp(Node u, Node v) { return u.s < v.s; }
inline bool cmp2(Line u, Line v) {
  if (u.r ^ v.r) return u.r < v.r;
  return u.l < v.l;
}
inline long long solve(long long st, long long en) {
  long long ans = 0;
  tot = 0;
  for (long long i = (st); i <= (en); i++)
    a[++tot] = (Line){max(0ll, d[i].a - d[i].m), min(d[i].a, d[i].s)},
    a[tot].v = d[i].a, a[tot].id = i;
  sort(a + 1, a + tot + 1, cmp2);
  long long pos = -1e18;
  for (long long i = (1); i <= (tot); i++) {
    if (pos < a[i].l) ans++, pos = a[i].r;
    x[a[i].id] = a[i].v - pos;
  }
  return ans;
}
inline void work() {
  n = read();
  for (long long i = (1); i <= (n); i++) {
    x[i] = rx[i] = ry[i] = 0;
    d[i].a = read(), d[i].b = read(), d[i].m = read();
    d[i].s = d[i].a + d[i].b - d[i].m, d[i].id = i;
  }
  sort(d + 1, d + n + 1, cmp);
  long long l = 0, r = 0, ans = 0;
  while (r <= n) {
    l = ++r;
    if (r > n) break;
    while (r + 1 <= n && d[r + 1].s == d[l].s) ++r;
    ans += solve(l, r);
  }
  cout << ans << endl;
  for (long long i = (1); i <= (n); i++)
    rx[d[i].id] = x[i], ry[d[i].id] = d[i].m - x[i];
  for (long long i = (1); i <= (n); i++) cout << rx[i] << ' ' << ry[i] << endl;
}
signed main() {
  long long tasks = read();
  while (tasks--) work();
  return 0;
}
