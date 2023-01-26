#include <bits/stdc++.h>
using namespace std;
int n, ans[110];
int main() {
  scanf("%d", &n);
  for (int u = 1; u <= n; u++)
    for (int i = 1; i <= n; i++) {
      if (ans[i]) continue;
      printf("? ");
      for (int j = 1; j <= n; j++)
        if (i == j)
          printf("%d ", n - u + 1);
        else
          printf("1 ");
      puts("");
      fflush(stdout);
      int k;
      scanf("%d", &k);
      if (k) {
        ans[i] = u;
        break;
      }
    }
  printf("! ");
  for (int i = 1; i <= n; i++) {
    if (!ans[i]) ans[i] = n;
    printf("%d ", ans[i]);
  }
  puts("");
}
