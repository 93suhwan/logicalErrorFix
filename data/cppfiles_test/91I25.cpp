#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9')
    x = (x << 3) + (x << 1) + (ch ^ 48), ch = getchar();
  return x * f;
}
int cas, n, a[100005], t[2][100005], b[2][100005], tot[2], ans, sum[2][100005];
int ceil(int x, int y) {
  if (x % y == 0)
    return x / y;
  else
    return x / y + 1;
}
int main() {
  cas = read();
  while (cas--) {
    n = read();
    for (int i = 1; i <= n; ++i) a[i] = read();
    ans = 0;
    for (int i = n, r = 1; i >= 1; --i, r ^= 1) {
      for (int j = 1; j <= tot[r ^ 1]; ++j) {
        ans += t[r ^ 1][b[r ^ 1][j]] * (ceil(a[i], b[r ^ 1][j]) - 1) +
               sum[r ^ 1][b[r ^ 1][j]];
        sum[r ^ 1][b[r ^ 1][j]] +=
            t[r ^ 1][b[r ^ 1][j]] * (ceil(a[i], b[r ^ 1][j]) - 1);
        int tr = a[i] / ceil(a[i], b[r ^ 1][j]);
        if (!t[r][tr]) b[r][++tot[r]] = tr;
        t[r][tr] += t[r ^ 1][b[r ^ 1][j]];
        sum[r][tr] += sum[r ^ 1][b[r ^ 1][j]];
        t[r ^ 1][b[r ^ 1][j]] = 0;
        sum[r ^ 1][b[r ^ 1][j]] = 0;
      }
      tot[r ^ 1] = 0;
      if (!t[r][a[i]]) b[r][++tot[r]] = a[i];
      t[r][a[i]]++;
    }
    printf("%d\n", ans);
    for (int i = 1; i <= tot[n & 1]; ++i) {
      t[n & 1][b[n & 1][i]] = 0;
      sum[n & 1][b[n & 1][i]] = 0;
    }
    tot[n & 1] = 0;
  }
  return 0;
}
