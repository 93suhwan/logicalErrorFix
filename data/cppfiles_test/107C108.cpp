#include <bits/stdc++.h>
using namespace std;
const int N = 1000005;
int t, n, a, b, x[N];
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 0; i <= n; ++i) x[i] = 0;
    if (abs(a - b) > 1 || n < a + b + 2) {
      printf("-1\n");
      continue;
    } else {
      if (a > b) {
        int tmp = n - (a + b + 2);
        for (int i = 1; i <= tmp; ++i) x[i] = i;
        for (int i = tmp + 1; i <= n; i += 2) x[i] = ((i - tmp) / 2 + 1) + tmp;
        for (int i = tmp + 2; i <= n; i += 2)
          x[i] = (n - tmp) - (x[i - 1] - tmp) + 1 + tmp;
      } else {
        int tmp = n - (a + b + 2);
        for (int i = 2 + tmp; i <= n; i += 2) x[i] = (i - tmp) / 2;
        for (int i = 1 + tmp; i <= n; i += 2) x[i] = (n - tmp) - x[i - 1];
        for (int i = 1; i <= tmp; ++i) x[i] = 2 * n - tmp + 1 - (i + n - tmp);
      }
    }
    for (int i = 1; i <= n; ++i) printf("%d ", x[i]);
    printf("\n");
  }
  return 0;
}
