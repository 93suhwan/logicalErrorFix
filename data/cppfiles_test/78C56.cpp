#include <bits/stdc++.h>
using namespace std;
int T, n, t[30], l[200005], tot;
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < 30; i++) t[i] = 0;
    for (int i = 1; i <= n; i++) {
      int a;
      scanf("%d", &a);
      for (int j = 0; j < 30; j++) t[j] += (a >> j) & 1;
    }
    for (int i = 1; i <= n; i++) l[i] = 0;
    tot = 0;
    for (int i = 0; i < 30; i++)
      if (t[i]) {
        ++tot;
        for (int j = 1; j * j <= t[i]; j++)
          if (t[i] % j == 0) {
            ++l[j];
            if (j != t[i] / j) ++l[t[i] / j];
          }
      }
    for (int i = 1; i <= n; i++)
      if (l[i] == tot) printf("%d ", i);
    putchar('\n');
  }
}
