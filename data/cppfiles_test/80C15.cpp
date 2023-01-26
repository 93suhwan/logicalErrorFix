#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int T, n, m, a[N], b[N], cnt, res[N << 1], v[N << 1], t, c[N << 1], pr[N],
    sf[N], p[N];
long long ans;
void add(int x, int y) {
  for (int i = x; i; i -= i & (-i)) c[i] += y;
}
int query(int x) {
  int ans = 0;
  for (int i = x; i <= t; i += i & (-i)) ans += c[i];
  return ans;
}
void solve(int l, int r, int nl, int nr) {
  if (l > r || nl > nr) return;
  int mid = (l + r) / 2, ans = 1e9;
  pr[nl - 1] = sf[nr + 1] = 0;
  for (int i = nl; i <= nr; i++) pr[i] = pr[i - 1] + (a[i] > b[mid]);
  for (int i = nr; i >= nl; i--) sf[i] = sf[i + 1] + (a[i] < b[mid]);
  for (int i = nl; i <= nr; i++)
    if (ans > pr[i - 1] + sf[i]) ans = pr[i - 1] + sf[i], p[mid] = i;
  solve(l, mid - 1, nl, p[mid]), solve(mid + 1, r, p[mid], nr);
}
signed main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &n, &m), cnt = ans = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
    sort(b + 1, b + 1 + m), solve(1, m + 1, 1, n + 1);
    for (int i = 1, j = 1; i <= n + 1; i++) {
      while (j <= m && p[j] <= i) res[++cnt] = b[j], j++;
      if (i <= n) res[++cnt] = a[i];
    }
    for (int i = 1; i <= cnt; i++) v[i] = res[i];
    sort(v + 1, v + 1 + cnt), t = unique(v + 1, v + 1 + cnt) - v - 1,
                              fill(c + 1, c + 1 + t, 0);
    for (int i = 1; i <= cnt; i++) {
      res[i] = lower_bound(v + 1, v + 1 + t, res[i]) - v;
      ans += query(res[i] + 1), add(res[i], 1);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
