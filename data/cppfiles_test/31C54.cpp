#include <bits/stdc++.h>
using namespace std;
const int N = 530005;
int n, k, i, t, m, j, len, a[N], ch[N * 20][2], p, tot, mn[N], mx[N], ans[N];
int as[20][N];
int Findmn(int i, int d, int x) {
  if (d == -1) return 0;
  if (ch[i][x >> d & 1])
    return Findmn(ch[i][x >> d & 1], d - 1, x);
  else
    return Findmn(ch[i][(x >> d & 1) ^ 1], d - 1, x) + (1 << d);
}
int Findmx(int i, int d, int x) {
  if (d == -1) return 0;
  if (ch[i][(x >> d & 1) ^ 1])
    return Findmx(ch[i][(x >> d & 1) ^ 1], d - 1, x) + (1 << d);
  else
    return Findmx(ch[i][x >> d & 1], d - 1, x);
}
void dfs(int i, int d) {
  if (!i || d == -1) return;
  if (ch[i][0] && ch[i][1]) {
    for (j = 0; j < (1 << d); ++j) {
      as[d + 1][j] = min(as[d + 1][j], (1 << d) - Findmx(ch[i][0], d - 1, j) +
                                           Findmn(ch[i][1], d - 1, j));
      as[d + 1][j + (1 << d)] =
          min(as[d + 1][j + (1 << d)], (1 << d) - Findmx(ch[i][1], d - 1, j) +
                                           Findmn(ch[i][0], d - 1, j));
    }
  }
  dfs(ch[i][0], d - 1);
  dfs(ch[i][1], d - 1);
}
int main() {
  scanf("%d %d", &n, &k);
  tot = 1;
  for (i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    p = 1;
    for (j = k - 1; j >= 0; --j) {
      if (!ch[p][a[i] >> j & 1]) ch[p][a[i] >> j & 1] = ++tot;
      p = ch[p][a[i] >> j & 1];
    }
  }
  for (i = 0; i <= k; ++i)
    for (j = 0; j < (1 << i); ++j) as[i][j] = 1 << 30;
  dfs(1, k - 1);
  for (i = 0; i < (1 << k); ++i) ans[i] = 1 << 30;
  for (i = 0; i <= k; ++i)
    for (j = 0; j < (1 << k); ++j) ans[j] = min(ans[j], as[i][j % (1 << i)]);
  for (i = 0; i < (1 << k); ++i) printf("%d ", ans[i]);
}
