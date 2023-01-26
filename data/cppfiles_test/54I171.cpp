#include <bits/stdc++.h>
int _, n, m, fa[500001], x, y, f, i, c[500001], cnt;
char s[100];
int find(int x) { return fa[x] < 0 ? x : fa[x] = find(fa[x]); }
void merge(int x, int y) {
  x = find(x);
  y = find(y);
  if (x == y) return;
  if (fa[x] < fa[y])
    fa[x] += fa[y], fa[y] = x;
  else
    fa[y] += fa[x], fa[x] = y;
}
int main() {
  scanf("%d", &_);
  while (_--) {
    scanf("%d%d", &n, &m);
    for (i = 1; i <= n << 1; i++) fa[i] = -1, c[i] = 0;
    cnt = 0;
    for (i = 1; i <= m; i++) {
      scanf("%d%d%s", &x, &y, s + 1);
      if (s[1] == 'i')
        f = 1;
      else
        f = 0;
      merge(x, y + f * n);
      merge(y + n - f * n, x + n);
    }
    for (i = 1; i <= n; i++) c[find(i)]--;
    for (i = n + 1; i <= n << 1; i++) c[find(i)]++;
    for (i = 1; i <= n; i++)
      if (find(i) == find(i + n)) {
        puts("-1");
        goto br;
      }
    for (i = n + 1; i <= n << 1; i++)
      if (c[find(i)] > 0) cnt++;
    printf("%d\n", cnt);
  br:;
  }
}
