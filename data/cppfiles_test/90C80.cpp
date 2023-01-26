#include <bits/stdc++.h>
using namespace std;
const int M = 200005;
const long long inf = 4e18;
long long read() {
  long long x = 0, f = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9') {
    if (c == '-') f = -1;
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
long long n, m, a[M], dp1, dp2, pre[M], suf[M];
vector<pair<long long, long long> > v[M];
void work() {
  n = read();
  m = read();
  for (long long i = 1; i <= n + 1; i++) v[i].clear();
  for (long long i = 1; i <= n; i++) a[i] = read();
  sort(a + 1, a + 1 + n);
  for (long long i = 1; i <= m; i++) {
    long long x = read(), y = read();
    long long p = lower_bound(a + 1, a + 1 + n, x) - a;
    if (p == n + 1) {
      v[p].push_back(make_pair(x, y));
      continue;
    }
    if (x <= a[p] && a[p] <= y) continue;
    v[p].push_back(make_pair(x, y));
  }
  for (long long i = 1; i <= n + 1; i++) sort(v[i].begin(), v[i].end());
  long long dis = 0;
  for (auto x : v[1]) dis = max(dis, a[1] - x.second);
  dp1 = dis;
  dp2 = 2 * dis;
  for (long long i = 2; i <= n; i++) {
    long long l = v[i].size();
    long long ndp1 = inf, ndp2 = inf;
    suf[l] = pre[0] = 0;
    for (long long j = l - 1; j >= 0; j--)
      suf[j] = max(suf[j + 1], a[i] - v[i][j].second);
    for (long long j = 1; j <= l; j++)
      pre[j] = max(pre[j - 1], v[i][j - 1].first - a[i - 1]);
    for (long long j = 0; j <= l; j++) {
      long long x = pre[j], y = suf[j];
      ndp1 = min(ndp1, dp1 + 2 * x + y);
      ndp1 = min(ndp1, dp2 + x + y);
      ndp2 = min(ndp2, dp2 + x + 2 * y);
      ndp2 = min(ndp2, dp1 + 2 * x + 2 * y);
    }
    dp1 = ndp1;
    dp2 = ndp2;
  }
  dis = 0;
  for (auto x : v[n + 1]) dis = max(dis, x.first - a[n]);
  dp1 += 2 * dis;
  dp2 += dis;
  printf("%lld\n", min(dp1, dp2));
}
signed main() {
  long long T = read();
  while (T--) work();
}
