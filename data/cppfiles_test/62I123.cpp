#include <bits/stdc++.h>
using namespace std;
int T, n, a[400006];
int main() {
  int t1, t2, t3, ans;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    if (a[n] == 0) {
      for (int i = 1; i <= n + 1; ++i) {
        printf("%d%c", i, " \n"[i == n + 1]);
      }
      continue;
    }
    if (a[1] == 1) {
      printf("%d ", n + 1);
      for (int i = 1; i <= n; ++i) {
        printf("%d%c", i, " \n"[i == n]);
      }
      continue;
    }
    printf("-1\n");
  }
}
