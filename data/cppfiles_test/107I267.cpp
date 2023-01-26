#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int t, n, a, b, x[N];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d", &n, &a, &b);
    if (a == b) {
      if (n != (2 * a + 2 * b)) {
        printf("-1\n");
        continue;
      } else {
        for (int i = 1; i <= n; i += 2) x[i] = i / 2 + 1;
        for (int i = 2; i <= n; i += 2) x[i] = n - x[i - 1] + 1;
      }
    } else {
      if (abs(a - b) != 1 || n < 2 * (a + b) - 1) {
        printf("-1\n");
        continue;
      } else {
        if (a > b) {
          int tmp = n - (2 * (a + b) - 1);
          for (int i = 1; i <= tmp; ++i) x[i] = i;
          for (int i = tmp + 1; i <= n; i += 2)
            x[i] = ((i - tmp) / 2 + 1) + tmp;
          for (int i = tmp + 2; i <= n; i += 2)
            x[i] = (n - tmp) - (x[i - 1] - tmp) + 1 + tmp;
        } else {
          int tmp = n - (2 * (a + b) - 1);
          for (int i = 2; i <= n - tmp; i += 2) x[i] = i / 2;
          for (int i = 1; i <= n - tmp; i += 2) x[i] = (n - tmp) - x[i - 1];
          for (int i = n - tmp + 1; i <= n; ++i) x[i] = i;
        }
      }
    }
    for (int i = 1; i <= n; ++i) printf("%d ", x[i]);
    printf("\n");
  }
  return 0;
}
