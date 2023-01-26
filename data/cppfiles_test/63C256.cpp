#include <bits/stdc++.h>
using namespace std;
const long long si = 1010;
long long n, m, mm;
long long pa[si][2];
long long root(long long x, long long p) {
  if (pa[x][p] != x) {
    return pa[x][p] = root(pa[x][p], p);
  }
  return pa[x][p];
}
void Union(long long x, long long y, long long p) {
  long long rx = root(x, p), ry = root(y, p);
  if (rx == ry) return;
  pa[rx][p] = ry;
  return;
}
bool inset(long long x, long long y, long long p) {
  return root(x, p) == root(y, p);
}
signed main() {
  scanf("%lld%lld%lld", &n, &m, &mm);
  for (register long long i = 1; i <= n; ++i) {
    pa[i][1] = pa[i][0] = i;
  }
  for (register long long i = 1; i <= m; ++i) {
    long long u, v;
    scanf("%lld%lld", &u, &v);
    Union(u, v, 0);
  }
  for (register long long i = 1; i <= mm; ++i) {
    long long u, v;
    scanf("%lld%lld", &u, &v);
    Union(u, v, 1);
  }
  long long cnt = n - 1 - max(m, mm);
  pair<long long, long long> ans[si];
  long long tot = 0;
  for (register long long i = 1; i < n; ++i) {
    for (register long long j = i + 1; j <= n; ++j) {
      if (inset(i, j, 0) || inset(i, j, 1)) continue;
      if (cnt == 0) break;
      cnt--, Union(i, j, 0), Union(i, j, 1);
      ans[++tot] = make_pair(i, j);
    }
    if (cnt == 0) break;
  }
  printf("%lld\n", tot);
  for (register long long i = 1; i <= tot; ++i) {
    printf("%lld %lld\n", ans[i].first, ans[i].second);
  }
  return 0;
}
