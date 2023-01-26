#include <bits/stdc++.h>
const int N = 2e5 + 5;
int T, n, a, b, ans[N];
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d %d", &n, &a, &b);
    if (abs(b - a) > 1 || a + b + 2 > n)
      puts("-1");
    else {
      if (a < b && (a > 0 || b > 0)) {
        int i = 1, j = n;
        for (int k = 1; k <= a + 1; k++, j--) ans[k * 2 - 1] = j;
        for (int k = 1; k <= b; k++, i++) ans[k * 2] = i;
        for (int k = a + b + 2; k <= n; k++, i++) ans[k] = i;
      } else if (a >= b && (a > 0 || b > 0)) {
        int i = 1, j = n;
        for (int k = 1; k <= a; k++, j--) ans[k * 2] = j;
        for (int k = 1; k <= b + 1; k++, i++) ans[k * 2 - 1] = i;
        for (int k = a + b + 2; k <= n; k++, j--) ans[k] = j;
      } else if (a == b && (a == 0 || b == 0)) {
        for (int i = 1; i <= n; i++) ans[i] = i;
      }
      for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
      puts("");
    }
  }
  return 0;
}
