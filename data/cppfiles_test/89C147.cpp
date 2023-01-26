#include <bits/stdc++.h>
int main() {
  int n, a;
  scanf("%d", &n);
  while (n--) {
    int n1;
    scanf("%d", &n1);
    int temp = 0;
    for (int i = 1; i <= n1; i++) {
      scanf("%d", &a);
      for (int j = i + 1; j >= 2; j--) {
        if (a % j != 0) {
          temp += 1;
          break;
        }
      }
    }
    if (temp != n1)
      printf("NO\n");
    else
      printf("YES\n");
  }
  return 0;
}
