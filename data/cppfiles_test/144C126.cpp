#include <bits/stdc++.h>
int tcase, n, m, K;
int main() {
  scanf("%d", &tcase);
  while (tcase--) {
    scanf("%d%d%d", &n, &m, &K);
    int x = 1;
    for (int k = 1; k <= K; k++) {
      int y = x;
      for (int i = 1; i <= n % m; i++) {
        printf("%d", n / m + 1);
        for (int j = 1; j <= n / m + 1; j++) printf(" %d", y), y = y % n + 1;
        printf("\n");
      }
      x = y;
      for (int i = 1; i <= m - n % m; i++) {
        printf("%d", n / m);
        for (int j = 1; j <= n / m; j++) printf(" %d", y), y = y % n + 1;
        printf("\n");
      }
    }
    printf("\n");
  }
  return 0;
}
