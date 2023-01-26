#include <bits/stdc++.h>
int t;
char a[2010], b[2010];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%s%s", a + 1, b + 1);
    int n = strlen(a + 1), m = strlen(b + 1);
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m && i + j - 1 <= n; j++)
        if (a[i + j - 1] != b[j])
          break;
        else {
          if (i + j - 1 - 1 < m - j) continue;
          int bk = 1;
          for (int p = j + 1, q = i + j - 1 - 1; q && p <= m; q--, p++)
            if (a[q] != b[p]) {
              bk = 0;
              break;
            }
          if (bk) {
            puts("YES");
            goto fo;
          }
        }
    }
    puts("NO");
  fo:;
  }
  return 0;
}
