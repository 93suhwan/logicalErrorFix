#include <bits/stdc++.h>
int cmp(const void *p, const void *q) { return (*(int *)p) - (*(int *)q); }
int a[100010];
int need[100010];
int main() {
  int t, n;
  int i;
  int m;
  int ans;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    ans = 0;
    m = n;
    for (i = 1; i <= n; i++) need[i] = 0;
    for (i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (i = 1; i <= n; i++) {
      if (a[i] <= n) {
        if (need[a[i]] == 0) {
          need[a[i]] = 1;
          a[i] = 0;
        }
      }
    }
    qsort(a + 1, n, sizeof(a[0]), cmp);
    for (i = 1; a[i] == 0 && i <= n; i++)
      ;
    m = i;
    for (i = 1; i <= n; i++) {
      if (need[i] == 1) continue;
      if (a[m] <= 2 * i) {
        printf("-1\n");
        ans = -1;
        break;
      }
      ans++;
      m++;
    }
    if (ans >= 0) printf("%d\n", ans);
  }
}
