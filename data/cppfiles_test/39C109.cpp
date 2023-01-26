#include <bits/stdc++.h>
using namespace std;
int n, ans[110];
int main() {
  scanf("%d", &n);
  for (int i = n; i > 0; i--) {
    printf("? ");
    for (int j = 1; j < n; j++) printf("1 ");
    printf("%d\n", i);
    fflush(stdout);
    int k;
    scanf("%d", &k);
    if (k) {
      ans[n] = n - i + 1;
      ans[k] = n;
      break;
    }
  }
  if (!ans[n]) ans[n] = n;
  for (int i = ans[n] + 1; i <= n; i++) {
    printf("? ");
    for (int j = 1; j < n; j++) printf("1 ");
    printf("%d\n", i - ans[n] + 1);
    fflush(stdout);
    int k;
    scanf("%d", &k);
    ans[k] = i;
  }
  for (int i = 1; i < ans[n]; i++) {
    printf("? ");
    for (int j = 1; j < n; j++) printf("%d ", ans[n] - i + 1);
    printf("1\n");
    fflush(stdout);
    int k;
    scanf("%d", &k);
    ans[k] = i;
  }
  printf("! ");
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
  puts("");
}
