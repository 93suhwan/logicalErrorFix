#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 5;
const int M = 1e3 + 5;
const int inf = 0x3f3f3f3f;
const int mod = 1e8 + 7;
const double eps = 1e-13;
const double pi = acos(-1.0);
long long read() {
  long long x = 0, t = 1;
  char ch;
  while ((ch = getchar()) < '0' || ch > '9')
    if (ch == '-') t = -1;
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + ch - '0';
    ch = getchar();
  }
  return x * t;
}
int f[N][M << 1];
int a[N];
int main() {
  int T = read();
  while (T--) {
    int n = read(), m = 2000;
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= m; j++) f[i][j] = inf;
    f[0][0] = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j <= m; j++) {
        if (f[i][j] == inf) continue;
        if (j + a[i + 1] <= m)
          f[i + 1][j + a[i + 1]] =
              min(f[i + 1][j + a[i + 1]], max(j + a[i + 1], f[i][j]));
        if (j - a[i + 1] >= 0)
          f[i + 1][j - a[i + 1]] = min(f[i + 1][j - a[i + 1]], f[i][j]);
        else
          f[i + 1][0] = min(f[i + 1][0], f[i][j] + a[i + 1] - j);
      }
    }
    int ans = inf;
    for (int i = 0; i <= m; i++) ans = min(ans, f[n][i]);
    printf("%d\n", ans);
  }
  return 0;
}
