#include <bits/stdc++.h>
int a[100000];
int main() {
  int n;
  memset(a, 0, sizeof(a));
  scanf("%d", &n);
  while (n--) {
    int n1;
    scanf("%d", &n1);
    int temp = 0, bo = 1;
    for (int i = 1; i <= n1; i++) {
      scanf("%d", &a[i]);
      bo = 0;
      for (int j = i + 1; j >= 2; j--) {
        if (a[i] % j != 0) {
          bo = 1;
          break;
        }
      }
    }
    if (bo == 0)
      printf("NO\n");
    else
      printf("YES\n");
  }
  return 0;
}
