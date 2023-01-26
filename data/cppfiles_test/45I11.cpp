#include <bits/stdc++.h>
int main() {
  int ara[100], t, sum, n, count;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    count = 0;
    scanf("%d", &n);
    sum = 1;
    for (int j = 0; j < n; j++) {
      scanf("%d", &ara[j]);
    }
    for (int j = 1; j < n; j++) {
      if (ara[j] == 0 && ara[j - 1] == 0) {
        count++;
        printf("-1\n");
        break;
      } else if (ara[j] == 1 && ara[j - 1] == 1) {
        sum = sum + 5;
      } else {
        sum = sum + 1;
      }
    }
    if (count == 0) {
      printf("%d\n", sum);
    }
  }
  return 0;
}
