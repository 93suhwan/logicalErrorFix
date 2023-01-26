#include <bits/stdc++.h>
using namespace std;
int a[200010];
int is[200010], col[200010], line[200010];
int n, m;
bool check(int x) {
  for (int i = 1; i <= n * m; i++) is[i] = 0, line[i] = 0, col[i] = 0;
  for (int i = 1; i <= n * m; i++) {
    if (a[i] >= x)
      is[i] = 1;
    else
      is[i] = 0;
  }
  for (int i = 1; i <= n * m; i++) {
    if (!is[i]) continue;
    int im = (i + n - 1) / n;
    int in = i - (im - 1) * n;
    col[in]++;
    line[im]++;
  }
  for (int i = 1; i <= n; i++)
    if (!col[i]) return 0;
  for (int i = 1; i <= m; i++)
    if (line[i] > 1) return 1;
  return 0;
}
void solve() {
  int maxx = 0;
  for (int i = 1; i <= n * m; i++) a[i] = 0, is[i] = 0, line[i] = 0, col[i] = 0;
  scanf("%d%d", &m, &n);
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++)
      scanf("%d", &a[(i - 1) * n + j]), maxx = max(maxx, a[(i - 1) * n + j]);
  int l = 1, r = maxx, ans;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      ans = mid, l = mid + 1;
    else
      r = mid - 1;
  }
  printf("%d\n", ans);
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
