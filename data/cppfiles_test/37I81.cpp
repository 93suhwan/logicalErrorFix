#include <bits/stdc++.h>
int *ej[100000], eo[100000];
void append(int i, int j) {
  int o = eo[i]++;
  if (o >= 2 && (o & o - 1) == 0)
    ej[i] = (int *)realloc(ej[i], o * 2 * sizeof *ej[i]);
  ej[i][o] = j;
}
int sz[100000];
void dfs(int p, int i) {
  int o;
  sz[i] = 1;
  for (o = eo[i]; o--;) {
    int j = ej[i][o];
    if (j != p) {
      dfs(i, j);
      sz[i] += sz[j];
    }
  }
}
int main() {
  int t;
  int timer = 0;
  scanf("%d", &t);
  while (t--) {
    timer++;
    static int ans[100000 + 1];
    int n, h, i, j, d, d_;
    scanf("%d", &n);
    for (i = 0; i < n; i++) ej[i] = (int *)malloc(2 * sizeof *ej[i]), eo[i] = 0;
    for (h = 0; h < n - 1; h++) {
      scanf("%d%d", &i, &j), i--, j--;
      append(i, j), append(j, i);
    }
    memset(ans, 0, (n + 1) * sizeof *ans), ans[1] = 1;
    for (h = 0; h < n - 1; h++) ans[1] = ans[1] * 2 % 998244353;
    dfs(-1, 0);
    for (d = 2; d <= n; d++)
      if ((sz[0] - 1) % d == 0) {
        int good = 1;
        for (i = 1; i < n; i++)
          if (sz[i] % d > 1) {
            good = 0;
            break;
          }
        if (good) ans[d]++;
      }
    for (d = n; d >= 1; d--)
      for (d_ = d + d; d_ <= n; d_ += d)
        ans[d] = (ans[d] - ans[d_] + 998244353) % 998244353;
    for (d = 1; d <= n; d++)
      if (timer < 3 || timer == 7) printf("%d ", ans[d]);
    printf("\n");
    for (i = 0; i < n; i++) free(ej[i]);
  }
  return 0;
}
