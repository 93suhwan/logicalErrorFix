#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int a[N][N];
int c[N][N];
int get_ans(int n, int m, int x, int y) {
  if (n == 1 && m == 1) return 0;
  int ans = 0;
  int tx = x, ty = y;
  while (tx < n && ty < m) tx++, ty++;
  c[tx][ty] = (1 - a[tx][ty]);
  for (int i = 1;; i++) {
    if (!tx || !ty) break;
    tx--, ty--;
    if (!tx || !ty) break;
    if (a[tx][ty])
      c[tx][ty] = 0;
    else
      c[tx][ty] = (1 - a[tx][ty]) + c[tx + 1][ty + 1];
  }
  tx++, ty++;
  int ttx = tx, tty = ty + 1;
  if (ty == m) {
    ttx = tx - 1, tty = m;
  }
  while (ttx < n && tty < m) ttx++, tty++;
  c[ttx][tty] = 1 - a[ttx][tty];
  for (int i = 1;; i++) {
    if (!ttx || !tty) break;
    ttx--, tty--;
    if (!ttx || !tty) break;
    if (a[ttx][tty])
      c[ttx][tty] = 0;
    else
      c[ttx][tty] = 1 - a[ttx][tty] + c[ttx + 1][tty + 1];
  }
  for (int i = 0; tx + i <= n && ty + i < m; i++) {
    if (c[tx + i][ty + i] == 0) continue;
    int l = c[tx + i][ty + i];
    int r = c[tx + i][ty + i + 1];
    ans += min(l, r);
    if (l > r)
      ans += r;
    else
      ans += l - 1;
  }
  ttx++, tty++;
  for (int i = 0; ttx + i < n && tty + i <= m; i++) {
    if (c[ttx + i][tty + i] == 0) continue;
    int u = c[ttx + i][tty + i];
    int d = c[ttx + i + 1][tty + i];
    ans += min(u, d);
    if (u > d)
      ans += d;
    else
      ans += u - 1;
  }
  ttx = tx + 1, tty = ty;
  if (tx == n) {
    ttx = tx;
    tty = ty - 1;
  }
  while (ttx < n && tty < m) ttx++, tty++;
  c[ttx][tty] = 1 - a[ttx][tty];
  for (int i = 1;; i++) {
    if (!ttx || !tty) break;
    ttx--, tty--;
    if (!ttx || !tty) break;
    if (a[ttx][tty])
      c[ttx][tty] = 0;
    else
      c[ttx][tty] = 1 - a[ttx][tty] + c[ttx + 1][tty + 1];
  }
  for (int i = 0; tx + i < n && ty + i <= m; i++) {
    if (c[tx + i][ty + i] == 0) continue;
    int u = c[tx + i][ty + i];
    int d = c[tx + i + 1][ty + i];
    ans += min(u, d);
    if (u > d)
      ans += d;
    else
      ans += u - 1;
  }
  ttx++, tty++;
  for (int i = 0; ttx + i <= n && tty + i < m; i++) {
    if (c[ttx + i][tty + i] == 0) continue;
    int l = c[ttx + i][tty + i];
    int r = c[ttx + i][tty + i + 1];
    ans += min(l, r);
    if (l > r)
      ans += r;
    else
      ans += l - 1;
  }
  return ans;
}
void solve() {
  int n, m, r;
  scanf("%d%d%d", &n, &m, &r);
  long long ans = n * m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < m; j++) {
      int l = min(n - i + 1, m - j + 1);
      int r = min(n - i + 1, m - j);
      ans += r;
      ans += l - 1;
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= m; j++) {
      int u = min(n - i + 1, m - j + 1);
      int d = min(n - i, m - j + 1);
      ans += d;
      ans += u - 1;
    }
  }
  while (r--) {
    int x, y;
    scanf("%d%d", &x, &y);
    ans -= get_ans(n, m, x, y);
    a[x][y] ^= 1;
    if (a[x][y])
      ans--;
    else
      ans++;
    ans += get_ans(n, m, x, y);
    printf("%lld\n", ans);
  }
}
int main() {
  int t = 1;
  while (t--) solve();
  return 0;
}
