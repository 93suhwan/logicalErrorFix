#include <bits/stdc++.h>
int main() {
  int count, t, n, i;
  scanf("%d", &t);
  while (t--) {
    count = 0;
    scanf("%d", &n);
    count += (int)sqrt(n);
    for (i = 1; i * i * i <= n; i++) {
      continue;
    }
    count += i - 1;
    for (i = 1; i * i * i * i * i * i <= n; i++) {
      continue;
    }
    count -= i - 1;
    printf("%d\n", count);
  }
}
