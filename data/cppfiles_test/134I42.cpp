#include <inttypes.h>
#include <stdio.h>

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    long long a[n];
    for (int i = 0; i < n; i++)
      scanf("%"PRId64"", &a[i]);

    int i = 0;
    for (; i < n; i++) {
      int prev = !!(a[0] % a[i]), cur, j = 1;
      for (; j < n; j++) {
        cur = !!(a[j] % a[i]);
        if (prev == cur) break;
        prev = cur;
      }
      if (j == n) {
        printf("%d\n", a[i]);
        break;
      }
    }
    if (i == n) printf("0\n");
  }

  return 0;
}
