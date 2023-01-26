#include <bits/stdc++.h>
int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }
int *ej[1000], eo[1000];
void append(int i, int j) {
  int o = eo[i]++;
  if (o >= 2 && (o & o - 1) == 0)
    ej[i] = (int *)realloc(ej[i], o * 2 * sizeof *ej[i]);
  ej[i][o] = j;
}
int aa[1000], bb[1000];
char cloud[1000];
int pp[1000];
int dfs(int p, int i, int s) {
  int o;
  pp[i] = p;
  for (o = eo[i]; o--;) {
    int j = ej[i][o];
    if (j != p && !cloud[j] && s > aa[j]) {
      if (pp[j] == -1) {
        if (dfs(i, j, min(s + bb[j], 0x3f3f3f3f))) return 1;
      } else {
        while (i != -1) cloud[i] = 1, i = pp[i];
        while (j != -1) cloud[j] = 1, j = pp[j];
        return 1;
      }
    }
  }
  return 0;
}
int solve(int n, int s) {
  memset(cloud, 0, n * sizeof *cloud), cloud[0] = 1;
  while (1) {
    int i, done, s_;
    done = 1;
    for (i = 0; i < n; i++)
      if (cloud[i] == 0) {
        done = 0;
        break;
      }
    if (done) return 1;
    s_ = s;
    for (i = 0; i < n; i++)
      if (cloud[i]) s_ = min(s_ + bb[i], 0x3f3f3f3f);
    memset(pp, -1, n * sizeof *pp);
    done = 1;
    for (i = 0; i < n; i++)
      if (cloud[i] && dfs(-1, i, s_)) {
        done = 0;
        break;
      }
    if (done) return 0;
  }
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, h, i, j, lower, upper;
    scanf("%d%d", &n, &m);
    for (i = 1; i < n; i++) scanf("%d", &aa[i]);
    for (i = 1; i < n; i++) scanf("%d", &bb[i]);
    for (i = 0; i < n; i++) ej[i] = (int *)malloc(2 * sizeof *ej[i]), eo[i] = 0;
    for (h = 0; h < m; h++) {
      scanf("%d%d", &i, &j), i--, j--;
      append(i, j), append(j, i);
    }
    lower = -1, upper = 0x3f3f3f3f;
    while (upper - lower > 1) {
      int s = (lower + upper) / 2;
      if (solve(n, s))
        upper = s;
      else
        lower = s;
    }
    printf("%d\n", upper);
    for (i = 0; i < n; i++) free(ej[i]);
  }
  return 0;
}
