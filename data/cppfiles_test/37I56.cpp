#include <bits/stdc++.h>
int t, n, m, book[100010];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      book[b] = 1;
    }
    for (int i = 1; i <= n; i++)
      if (!book[i]) {
        for (int j = 1; j <= n; j++)
          if (i != j) printf("%d %d\n", i, j);
        break;
      }
  }
  return 0;
}
