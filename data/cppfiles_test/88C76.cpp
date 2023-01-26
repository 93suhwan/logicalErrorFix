#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int n, m, a[N], b[N], cnt[N], tot[N], s[305][305];
int num[305], cl[N], cr[N];
void solve() {
  scanf("%d%d", &n, &m);
  memset(s, 0, sizeof(s));
  memset(num, 0, sizeof(num));
  memset(cl, 0, sizeof(cl));
  memset(cr, 0, sizeof(cr));
  for (int i = 1; i <= n * m; i++) scanf("%d", &a[i]), b[i] = a[i];
  sort(b + 1, b + n * m + 1);
  int sz = unique(b + 1, b + n * m + 1) - b - 1;
  int ans = 0;
  for (int i = 1; i <= n * m; i++) cnt[i] = tot[i] = 0;
  for (int i = 1; i <= n * m; i++) {
    int x = lower_bound(b + 1, b + sz + 1, a[i]) - b;
    cnt[x]++;
    a[i] = x;
  }
  for (int i = 1; i <= sz; i++) cnt[i] += cnt[i - 1];
  for (int i = 1; i <= n * m; i++) {
    int l = cnt[a[i] - 1] + 1, r = cnt[a[i]];
    int pl = (l + tot[a[i]] - 1) / m + 1, pr = (r - 1) / m + 1, p, x, y;
    if (pl == pr)
      x = pr, y = (r - cr[a[i]] - 1) % m + 1, cr[a[i]]++;
    else
      x = pl, y = m - num[x], num[x]++;
    for (int j = 1; j < y; j++) ans += s[x][j];
    tot[a[i]]++;
    s[x][y]++;
  }
  printf("%d\n", ans);
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
}
