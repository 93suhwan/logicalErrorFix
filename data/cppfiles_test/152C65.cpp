#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char c = getchar();
  int x = 0;
  bool f = 0;
  for (; !isdigit(c); c = getchar()) f ^= !(c ^ 45);
  for (; isdigit(c); c = getchar()) x = (x << 1) + (x << 3) + (c ^ 48);
  if (f) x = -x;
  return x;
}
int n, p[1000005];
int f[1000005][2], pre[1000005][2];
void chkmin(int x, int y, int z, int o) {
  if (z < f[x][y]) f[x][y] = z, pre[x][y] = o;
}
int res[1000005];
void work() {
  n = read();
  for (register int i = (1); i <= (n); ++i) p[i] = read();
  f[1][0] = -0x3f3f3f3f, f[1][1] = -0x3f3f3f3f;
  for (register int i = (2); i <= (n); ++i) {
    f[i][0] = f[i][1] = 0x3f3f3f3f;
    for (register int j = (0); j <= (1); ++j)
      for (register int k = (0); k <= (1); ++k) {
        int now = (j ? p[i] : -p[i]);
        int lst = (k ? p[i - 1] : -p[i - 1]);
        if (now > lst) chkmin(i, j, f[i - 1][k], k);
        if (now > f[i - 1][k]) chkmin(i, j, lst, k);
      }
  }
  if (f[n][0] > n && f[n][1] > n) {
    puts("NO");
    return;
  }
  puts("YES");
  int o = (f[n][1] <= n);
  res[n] = (o ? p[n] : -p[n]);
  for (register int i = (n - 1); i >= (1); --i) {
    o = pre[i + 1][o];
    res[i] = (o ? p[i] : -p[i]);
  }
  for (register int i = (1); i <= (n); ++i) printf("%d ", res[i]);
  puts("");
}
signed main() {
  int T = read();
  while (T--) work();
  return 0;
}
