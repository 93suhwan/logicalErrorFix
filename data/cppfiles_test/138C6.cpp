#include <bits/stdc++.h>
using namespace std;
struct Node {
  long long fa, l, r, tot;
  Node() {}
};
struct Edge {
  long long u, v, w;
  Edge() {}
  bool operator<(const Edge &x) const { return w < x.w; }
};
const long long MAX_N = 4e5 + 7;
long long sum_a[MAX_N], sum_v[MAX_N], sum[MAX_N], ans[MAX_N];
pair<long long, long long> qry[MAX_N], a[MAX_N];
Node dsu[MAX_N];
Edge e[MAX_N];
long long n, m, q;
long long find(long long x) {
  return dsu[x].fa == x ? x : dsu[x].fa = find(dsu[x].fa);
}
signed main() {
  scanf("%lld%lld%lld", &n, &m, &q);
  for (long long i = 1; i <= n; ++i)
    scanf("%lld", &a[i].first), a[i].second = i, sum[0] += a[i].first;
  for (long long i = 1; i <= m; ++i)
    scanf("%lld", &a[i + n].first), a[i + n].second = i + n;
  sort(a + 1, a + 1 + n + m);
  for (long long i = 1; i <= n + m; ++i) {
    dsu[i].fa = i, dsu[i].l = dsu[i].r = i;
    if (i != n + m)
      e[i].u = i, e[i].v = i + 1, e[i].w = a[i + 1].first - a[i].first;
    sum_v[i] += sum_v[i - 1];
    sum_a[i] += sum_a[i - 1] + a[i].first;
    dsu[i].tot = 0;
    if (a[i].second <= n) ++sum_v[i], dsu[i].tot += a[i].first;
  }
  for (long long i = 1; i <= q; ++i) {
    scanf("%lld", &qry[i].first);
    qry[i].second = i;
  }
  sort(qry + 1, qry + 1 + q);
  sort(e + 1, e + n + m);
  long long pos = 0;
  for (long long i = 1; i < n + m; ++i) {
    long long u = e[i].u, v = e[i].v, w = e[i].w;
    long long fu = find(u), fv = find(v);
    long long l = min(dsu[fu].l, dsu[fv].l), r = max(dsu[fu].r, dsu[fv].r);
    long long num = sum_v[r] - sum_v[l - 1];
    long long tot = sum_a[r] - sum_a[r - num] - dsu[fu].tot - dsu[fv].tot;
    dsu[fu].fa = fv;
    dsu[fv].l = l, dsu[fv].r = r, dsu[fv].tot = sum_a[r] - sum_a[r - num];
    while (pos <= q && qry[pos].first < w) ++pos;
    if (pos <= q) sum[pos] += tot;
  }
  for (long long i = 1; i <= q; ++i) {
    sum[i] += sum[i - 1];
    ans[qry[i].second] = sum[i];
  }
  for (long long i = 1; i <= q; ++i) printf("%lld\n", ans[i]);
  return 0;
}
