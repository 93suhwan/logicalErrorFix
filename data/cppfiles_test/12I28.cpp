#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int n, m, ans[N][N], lst[N][N], ny, q[N], t, w, f[N][N];
char a[N][N];
double x(int i) { return i; }
double y(int i) {
  return i * i + lst[ny][i] * lst[ny][i] - 2 * ny * lst[ny][i];
}
double slope(int i, int j) { return (y(i) - y(j)) / (x(i) - x(j)); }
void solve() {
  for (int j = 1; j <= m; ++j) {
    lst[0][j] = -114514;
    for (int i = 1; i <= n; ++i) {
      lst[i][j] = lst[i - 1][j];
      if (a[i][j] == '1') lst[i][j] = i;
    }
  }
  for (int i = 1; i <= n; ++i) {
    ny = i;
    t = 1;
    w = 0;
    for (int j = 1; j <= m; ++j) {
      while (t < w && slope(q[w - 1], q[w]) > slope(q[w], j)) --w;
      q[++w] = j;
      while (t < w && slope(q[t], q[t + 1]) < 2 * j) ++t;
      f[i][j] =
          (j - q[t]) * (j - q[t]) + (i - lst[i][q[t]]) * (i - lst[i][q[t]]);
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  ++n;
  ++m;
  for (int i = 1; i <= n; ++i) scanf("%s", a[i] + 1);
  memset(ans, 0x3f, sizeof(ans));
  solve();
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) ans[i][j] = min(ans[i][j], f[i][j]);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m / 2; ++j) swap(a[i][j], a[i][m - j + 1]);
  solve();
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) ans[i][j] = min(ans[i][j], f[i][m - j + 1]);
  for (int i = 1; i <= n / 2; ++i)
    for (int j = 1; j <= m; ++j) swap(a[i][j], a[n - i + 1][j]);
  solve();
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      ans[i][j] = min(ans[i][j], f[n - i + 1][m - j + 1]);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m / 2; ++j) swap(a[i][j], a[i][m - j + 1]);
  solve();
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) ans[i][j] = min(ans[i][j], f[n - i + 1][j]);
  int res = 0;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) res += ans[i][j];
  printf("%d", res);
  return 0;
}
