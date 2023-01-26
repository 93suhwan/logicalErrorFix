#include <bits/stdc++.h>
using namespace std;
const long long N = 2 * 1e5 + 100;
long long n, k, L[N], R[N], cnt, tr[N], fa[N], vi[N];
vector<long long> e[N];
inline long long read() {
  long long f = 1, x = 0;
  char s = getchar();
  while (s < '0' || s > '9') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while (s >= '0' && s <= '9') {
    x = x * 10 + s - '0';
    s = getchar();
  }
  return x * f;
}
namespace seg {
long long tag[N * 4];
pair<long long, long long> MAX[N * 4];
inline void pushup(long long x) { MAX[x] = max(MAX[x + x], MAX[x + x + 1]); }
void pushdown(long long x) {
  if (!tag[x]) return;
  tag[x + x] += tag[x];
  tag[x + x + 1] += tag[x];
  MAX[x + x].first += tag[x];
  MAX[x + x + 1].first += tag[x];
  tag[x] = 0;
}
void build(long long x, long long l, long long r) {
  tag[x] = 0;
  if (l == r) {
    MAX[x] = make_pair(0, l);
    return;
  }
  long long mid = (l + r) >> 1;
  build(x + x, l, mid);
  build(x + x + 1, mid + 1, r);
  pushup(x);
}
void change(long long x, long long l, long long r, long long ll, long long rr,
            long long v) {
  if (ll <= l && rr >= r) {
    tag[x] += v, MAX[x].first += v;
    return;
  }
  long long mid = (l + r) >> 1;
  pushdown(x);
  if (ll <= mid) change(x + x, l, mid, ll, rr, v);
  if (rr > mid) change(x + x + 1, mid + 1, r, ll, rr, v);
  pushup(x);
}
pair<long long, long long> query(long long x, long long l, long long r,
                                 long long ll, long long rr) {
  if (ll <= l && rr >= r) return MAX[x];
  long long mid = (l + r) >> 1;
  pushdown(x);
  pair<long long, long long> ans =
      make_pair(-0x3f3f3f3f3f3f3f3f, -0x3f3f3f3f3f3f3f3f);
  if (ll <= mid) ans = max(ans, query(x + x, l, mid, ll, rr));
  if (rr > mid) ans = max(ans, query(x + x + 1, mid + 1, r, ll, rr));
  return ans;
}
}  // namespace seg
void dfs(long long x, long long father) {
  fa[x] = father;
  if (x != 1) e[x].erase(find(e[x].begin(), e[x].end(), fa[x]));
  if ((long long)e[x].size() == 0) {
    L[x] = R[x] = ++cnt;
    tr[cnt] = x;
    return;
  }
  L[x] = 0x3f3f3f3f3f3f3f3f;
  for (long long u : e[x]) dfs(u, x), L[x] = min(L[x], L[u]);
  R[x] = cnt;
}
long long f(long long a) {
  a = min(a, n / 2);
  return a * a - n * a;
}
signed main() {
  n = read();
  k = read();
  for (long long i = 1; i < n; i++) {
    long long u = read(), v = read();
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs(1, 0);
  seg::build(1, 1, cnt);
  for (long long i = 1; i <= n; i++) seg::change(1, 1, cnt, L[i], R[i], 1);
  long long ans = -0x3f3f3f3f3f3f3f3f, lim = min(k, cnt), now = 0;
  for (long long i = 1; i <= lim; i++) {
    now += seg::MAX[1].first;
    long long x = tr[seg::MAX[1].second];
    while (!vi[x] && x) {
      seg::change(1, 1, cnt, L[x], R[x], -1);
      vi[x] = 1;
      x = fa[x];
    }
    ans = max(ans, f(n - now) + i * (n - i));
  }
  for (long long i = lim + 1; i <= k; i++)
    ans = max(ans, f(n - now) + i * (n - i));
  printf("%lld\n", ans);
}
