#include <bits/stdc++.h>
int main() {
  int test, n, i, j, height = 1;
  int day[101] = {0};
  scanf("%d", &test);
  for (i = 1; i <= test; i++) {
    height = 1;
    scanf("%d", &n);
    for (j = 1; j <= n; j++) {
      scanf("%d", &day[j]);
    }
    for (j = 1; j < n && height > 0; j++) {
      if (day[j] == day[j + 1] && day[j] == 0) height = 0;
    }
    if (height == 0) {
      printf("-1");
      if (i != test) printf("\n");
    } else {
      for (j = 1; j <= n; j++) {
        if (day[j] * day[j - 1] == 1)
          height += 5;
        else if (day[j] == 1 && day[j - 1] == 0)
          height += 1;
        else if (day[j] == 0)
          height = height;
      }
      printf("%d", height);
      if (i != test) printf("\n");
    }
  }
  return 0;
}
